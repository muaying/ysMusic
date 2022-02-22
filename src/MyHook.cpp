//
// Created by 24100 on 2022/2/21.
//

#include "MyHook.h"
#include <QDebug>
MyHook* MyHook::obj= MyHook::getMyHook();
HHOOK MyHook::keyHook= nullptr;
QSet<QString> MyHook::HotKeySet;

MyHook::MyHook() {}
MyHook* MyHook::getMyHook()
{
	if(obj== nullptr)
		obj=new MyHook();
	return  obj;
}

int MyHook::install()
{
	if(keyHook!=nullptr)
		UnhookWindowsHookEx(keyHook);
	keyHook = SetWindowsHookEx(WH_KEYBOARD_LL,MyHook::keyProc,nullptr,0);
	return GetLastError();
}

void MyHook::uninstall()
{
	if(keyHook!= nullptr)
	{
		UnhookWindowsHookEx(keyHook);
		keyHook= nullptr;
		delete obj;
		obj= nullptr;
	}
	HotKeySet.clear();
}

void MyHook::handleKeyDown(unsigned int Virtual_Key)
{
	qDebug()<<"key enter:"<<QString::number(Virtual_Key,16);
	emit KeyDownd(Virtual_Key);
}

LRESULT MyHook::keyProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if(wParam==WM_KEYDOWN)
		MyHook::getMyHook()->handleKeyDown(((KBDLLHOOKSTRUCT*)lParam)->vkCode);
	return CallNextHookEx(keyHook,nCode,wParam,lParam);     //继续原有的事件队列
}
MyHotKey::MyHotKey():m_nKey1(0),m_nKey2(0) {}

MyHotKey::~MyHotKey() noexcept{unregisterKey();}
bool MyHotKey::registerKey(QString key)
{
	if(key.size()>16)
		return false;
	unregisterKey();
	key=key.toUpper();
	//解析出按键 为 uint   形如  CTRL+F6
	auto it= std::find(key.begin(), key.end(), '+');
	if(it<key.end())
	{
		//存在组合键
		QString tmp;
		auto i=key.cbegin();
		while(i<it)
		{
			tmp.append(*i);
			++i;
		}
		if(tmp=="CTRL")
			m_nKey2=VK_CONTROL;
		else if(tmp=="ALT")
			m_nKey2=VK_MENU;
		else
			return false;
		tmp.clear();
		for(++it;it<key.end();++it)
			tmp.append(*it);
		if(tmp.size()>=2&&tmp.size()<=3&&tmp[0]=='F')
		{
			tmp.remove('F');
			bool ok;
			int n=tmp.toInt(&ok);
			if(ok==true&&n<13&&n>0)
				m_nKey1=VK_F1+n-1;
		}
		QString id=QString::number(m_nKey2)+QString::number(m_nKey1);
		if(!MyHook::HotKeySet.contains(id))
		{
			MyHook::HotKeySet.insert(id);
			connect(MyHook::getMyHook(),&MyHook::KeyDownd,this,&MyHotKey::handle);
			return true;
		}
	}
	else if(key.size()>=2&&key.size()<=3&&key[0]=='F')
	{
		//获取 Fx
		key.remove('F');
		bool ok;
		int n=key.toInt(&ok);
		if(ok==true&&n<13&&n>0)
			m_nKey1=VK_F1+n-1;
		m_nKey2=0;
		QString id=QString::number(m_nKey2)+QString::number(m_nKey1);
		if(!MyHook::HotKeySet.contains(id))
		{
			MyHook::HotKeySet.insert(id);
			connect(MyHook::getMyHook(),&MyHook::KeyDownd,this,&MyHotKey::handle);
			return true;
		}
	}
	m_nKey1=0;
	m_nKey2=0;
	return false;
}
void MyHotKey::unregisterKey()
{
	QString id=QString::number(m_nKey2)+QString::number(m_nKey1);
	if(MyHook::HotKeySet.remove(id))
	{
		disconnect(MyHook::getMyHook(),0,this,0);
	}
}

void MyHotKey::handle(unsigned int vk)
{
	if(m_nKey1==vk)
		if(m_nKey2==0)
		{
			//按下了复合键 不触发
			if(!(GetAsyncKeyState(VK_CONTROL) or GetAsyncKeyState(VK_MENU)))
					emit active();
		}
		else
			if(GetAsyncKeyState(m_nKey2))
				emit active();
}