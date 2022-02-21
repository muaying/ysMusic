//
// Created by 24100 on 2022/1/22.
//

#ifndef YSMUSIC_PLAYER_H
#define YSMUSIC_PLAYER_H

#include <QObject>

/**
 * 弹奏者类
 * 负责 弹奏解析好的琴谱
 * QList<std::pair<QString,int>> 琴谱的数据结构
 * QString 按键信息
 * int 延时信息
**/

class Player : public QObject
{
    Q_OBJECT
public:
    Player(QObject *parent = nullptr);

	//是否弹奏完成
    bool isPlaying()const;
	//控制暂停  true暂停 false 继续播放
	void setPause(bool pause);
	bool isPause()const;
	//控制 弹奏状态 true： 运行弹奏  false：无法弹奏 并且让 正在弹奏的格局结束弹奏
	void setFlag(bool flag);
public
    slots:
	//弹奏执行函数
            void play(QList<std::pair<QString,int>>& musics);
    signals:

private:
    bool flag;
	bool pause;
//正在弹奏标志
    bool playing;
    void playKey(QString keys);
};


#endif //YSMUSIC_PLAYER_H
