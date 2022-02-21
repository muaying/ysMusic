//
// Created by 24100 on 2022/1/30.
//

#ifndef YSMUSIC_MUSIC_H
#define YSMUSIC_MUSIC_H


#include <QString>
#include <QList>

class Music {
public:
	static Music* createMusic(QString filename,QString& status);//工厂函数
	QList<std::pair<QString,int>>& getSheet();
	QString getName()const;
	QString getAuthor()const;
	QString toString()const;
private:
	Music(QString author,QString name);
	bool analyze1(QString& strSheet,int delay);//解析琴谱
private:
	QList<std::pair<QString,int>> m_sheet;//分析后的结果
	QString m_author;//作者
	QString m_name;//音乐名字
};


#endif //YSMUSIC_MUSIC_H
