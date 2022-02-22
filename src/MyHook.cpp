//
// Created by 24100 on 2022/2/21.
//

#include "MyHook.h"
#include <QDebug>
#include <chrono>
MyHook* MyHook::obj= MyHook::getMyHook();
HHOOK MyHook::keyHook= nullptr;

MyHook::MyHook():flag(false) {}
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
}

void MyHook::handleKeyDown(unsigned int Virtual_Key)
{
	emit KeyDownd(Virtual_Key);
	if(flag==true&& Virtual_Key<='Z'&&Virtual_Key>='A')
	{
		using namespace std::chrono;
		//获取当前时间毫秒数
		int now=duration_cast<milliseconds>(steady_clock:: now().time_since_epoch()).count();
		auto p=std::make_pair(Virtual_Key,now);
		SheetBuffer.append(p);
	}
}

void MyHook::beginRecording()
{
	flag=true;
	SheetBuffer.clear();
}

const QList<std::pair<unsigned int, int>>& MyHook::endRecording()
{
	flag=false;
	return SheetBuffer;
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
		if(!MyHook::getMyHook()->HotKeySet.contains(id))
		{
			MyHook::getMyHook()->HotKeySet.insert(id);
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
		if(!MyHook::getMyHook()->HotKeySet.contains(id))
		{
			MyHook::getMyHook()->HotKeySet.insert(id);
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
	if(MyHook::getMyHook()->HotKeySet.remove(id))
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