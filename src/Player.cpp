//
// Created by 24100 on 2022/1/22.
//

#include "Player.h"
#include <QDebug>
#include <windows.h>
#include <QThread>

Player::Player(QObject *parent) : QObject(parent) {
    playing = false;
	flag=false;
	pause=false;
}

bool Player::isPlaying()const {
    return playing;
}

void Player::play(QList <std::pair<QString, int>>& musics)
{
	playing=true;
//	qDebug()<<"正在弹奏";
	auto m=musics.begin();
	while(flag&&m!=musics.end())
	{
		if(pause==false)
		{
//			qDebug()<<"按键"<<m->first;
//			qDebug()<<"延时"<<m->second;
			playKey(m->first);
			QThread::msleep(m->second);
			++m;
		}else
		{
			QThread::msleep(500);
		}
	}
	//qDebug()<<"弹奏完成";
	playing=false;
}
void Player::playKey(QString keys)
{
    for(auto k:keys)
        keybd_event(k.toLatin1(),0,0,0);
	for(auto it=keys.rbegin();it!=keys.rend();++it)
		keybd_event(it->toLatin1(),0,KEYEVENTF_KEYUP,0);
}
void Player::setFlag(bool flag) {this->flag = flag;}
void Player::setPause(bool pause) { this->pause=pause;}

bool Player::isPause() const {return pause;}