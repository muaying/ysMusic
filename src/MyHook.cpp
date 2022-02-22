//
// Created by 24100 on 2022/2/21.
//

#include "MyHook.h"
#include <QDebug>
MyHook* MyHook::obj= MyHook::getMyHook();
HHOOK MyHook::keyHook= nullptr;

MyHook::MyHook() {}
MyHook* MyHook::getMyHook()
{
	if(obj== nullptr)
	{
		if(keyHook!=nullptr)
			UnhookWindowsHookEx(keyHook);
		obj=new MyHook();
		keyHook = SetWindowsHookEx(WH_KEYBOARD_LL,MyHook::keyProc,nullptr,0);
	}
	return  obj;
}
MyHook::~MyHook() noexcept
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
	qDebug()<<"key enter:"<<QString::number(Virtual_Key,16);
	emit KeyDownd(Virtual_Key);
}

LRESULT MyHook::keyProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if(wParam==WM_KEYDOWN)
		MyHook::getMyHook()->handleKeyDown(((KBDLLHOOKSTRUCT*)lParam)->vkCode);
	return CallNextHookEx(keyHook,nCode,wParam,lParam);     //继续原有的事件队列
}

