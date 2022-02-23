//
// Created by 24100 on 2022/1/30.
//

#ifndef YSMUSIC_MUSIC_H
#define YSMUSIC_MUSIC_H
#include <QTextStream>

#include <QString>
#include <QList>
#include <QFile>

class Music {
public:
	static Music*  createMusic(QString filename,QString& status);//工厂函数
	static Music*  createMusic(QString name,QString author,const QList<std::pair<unsigned int,int>>& sheet);
	QList<std::pair<QString,int>>& getSheet();
	void toFile(QTextStream& stream,bool hasDelay)const;

	QString getName()const;
	QString getAuthor()const;
	QString toString()const;
private:
	Music(QString author,QString name);
	bool analyze1(QString& strSheet,int delay);//解析琴谱
//	bool analyze2(QString& strSheet,int bmp);//琴谱类型3
private:
	QList<std::pair<QString,int>> m_sheet;//分析后的结果
	QString m_author;//作者
	QString m_name;//音乐名字
};


#endif //YSMUSIC_MUSIC_H
