//
// Created by 24100 on 2022/1/22.
//

#include "Player.h"
#include <QDebug>
#include <windows.h>
#include <QThread>

Player::Player(QObject *parent) : QObject(parent)
{
    playing = false;
}

bool Player::isPlaying()
{
    return playing;
}

void Player::play(QString
sheet,
int delay
)
{
playing = true;
auto it = sheet.cbegin();
while(
flag &&it
!=sheet.

cend()

)
{

qDebug()

<<"正在弹奏";
playKey(it
->

toLatin1()

);
++
it;
QThread::msleep(delay);
}

qDebug()

<<"弹奏完成";
playing = false;
}

void Player::playKey(char key)
{
    keybd_event(key, 0, 0, 0);
    keybd_event(key, 0, KEYEVENTF_KEYUP, 0);
}


void Player::playKey(char key1, char key2)
{
    keybd_event(key1, 0, 0, 0);
    keybd_event(key2, 0, 0, 0);
    keybd_event(key1, 0, KEYEVENTF_KEYUP, 0);
    keybd_event(key2, 0, KEYEVENTF_KEYUP, 0);
}

void Player::setPlayFlag(bool flag)
{
    this->flag = flag;
}