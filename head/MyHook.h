//
// Created by 24100 on 2022/2/21.
//

#ifndef YSMUSIC_MYHOOK_H
#define YSMUSIC_MYHOOK_H
#include <QObject>
#include <windows.h>
#include <QSet>
class MyHotKey;//热键类


//单例设计模式
class MyHook: public QObject{
	Q_OBJECT
	friend class MyHotKey;
public:
	static MyHook* getMyHook();
	//注册 销毁 钩子
	int install();
	void uninstall();
	//回调函数
	void handleKeyDown(unsigned int Virtual_Key);
	static LRESULT CALLBACK keyProc(int nCode,WPARAM wParam,LPARAM lParam);
	signals:
	void KeyDownd(unsigned int Virtual_Key);
private:
	MyHook();
	static MyHook* obj;
	static HHOOK keyHook;
	static QSet<QString> HotKeySet;//热键表
};


//热键类
class MyHotKey:public  QObject
{
Q_OBJECT
public:
	MyHotKey();
 	~MyHotKey();
	bool registerKey(QString key);
	void unregisterKey();
	signals:
	void active();//热键触发信号
private slots:
	void handle(unsigned int vk);
private:
	unsigned int m_nKey1;//主键
	unsigned int m_nKey2;// 副键
};

#endif //YSMUSIC_MYHOOK_H
