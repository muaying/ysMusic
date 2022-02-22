//
// Created by 24100 on 2022/2/21.
//

#ifndef YSMUSIC_MYHOOK_H
#define YSMUSIC_MYHOOK_H
#include <QObject>
#include <windows.h>

//单例设计模式
class MyHook: public QObject{
	Q_OBJECT
public:
	static MyHook* getMyHook();
	//回调函数
	void handleKeyDown(unsigned int Virtual_Key);
	~MyHook();

	static LRESULT CALLBACK keyProc(int nCode,WPARAM wParam,LPARAM lParam);
private:

	signals:
	void KeyDownd(unsigned int Virtual_Key);
private:
	MyHook();
	static MyHook* obj;
	static HHOOK keyHook;
};

class myHotKey:public  QObject
{
Q_OBJECT
public:

private:

};

#endif //YSMUSIC_MYHOOK_H
