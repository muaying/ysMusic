//
// Created by 24100 on 2022/1/30.
//

#include "Music.h"
#include <QFile>

//工厂函数
//根据文件名 创建music
Music *Music::createMusic(QString filename, QString &status)
{
	QFile qFile(filename);
	QString author="";
	QString name="";
	if(qFile.open(QFile::ReadOnly))
	{
		QByteArray data = qFile.readAll();
		qFile.close();
		//获取 作者 曲名 以及  曲谱 去除所有空格行号 以及文件 结束标志
		QByteArray buf;
		QString strSheet;
		int delay = 100;
		for (auto it = data.cbegin(); it < data.cend(); ++it)
		{
			if (*it == ' ' || *it == '\n' || *it == '\r') {
				continue;
			} else if (*it == ':') {
				QByteArray tmp;
				while (*it != ',' && it != data.cend() && *it != '\x00') {
					++it;
					if (*it == ' ' || *it == '\n' || *it == '\r' || *it == ',' || *it == '\x00')
						continue;
					tmp.append(*it);
				}
				if (buf == "author")
					author = tmp;
				else if (buf == "musicName")
					name = tmp;
				else if (buf == "delay") {
					bool ok;
					int val = tmp.toInt(&ok);
					if (ok)
						delay = val;
				} else if (buf == "sheet")
					strSheet = tmp;
				buf.clear();
			} else
				buf.append(*it);
		}

		if(!strSheet.isEmpty())
		{
			Music* ret=new Music(author,name);
			try
			{
				if(ret->analyze1(strSheet,delay))
				{
					status ="加载成功";
					return ret;
				}
				else
				{
					status="解析琴谱失败";
					return nullptr;
				}
			}
			catch (std::exception e)
			{
				status=e.what();
				return nullptr;
			}
		}
		else
		{
			status="文件格式错误";
			return nullptr;
		}
	}
	status="文件打开失败";
	return nullptr;
}
//根据按键 信息绘制琴谱

Music *Music::createMusic(QString name,QString author,const QList<std::pair<unsigned int,int>>& sheet)
{
	if(sheet.isEmpty())
		return nullptr;
	Music* ret=new Music(author,name);
	int timePoint=sheet[0].second;
	QString sBuf;
	for(auto& item:sheet)
	{
		//小于5ms表示 同时按下
		int d=item.second-timePoint;
		if(d<5)
		{
			sBuf.append(QChar(item.first));
			timePoint=item.second;
		}
		else
		{
			//得到一个  拍子 存入
			ret->m_sheet.append(std::make_pair(sBuf,d));
			//录取下一个 拍子
			sBuf.clear();
			sBuf.append(QChar(item.first));
			timePoint=item.second;
		}
	}
	if(!ret->m_sheet.isEmpty())
		return ret;
	else
		delete ret;
	return nullptr;
}

void Music::toFile(QTextStream& stream,bool hasDelay)const
{
	stream<<"author:"<<m_author<<",\nmusicName:"<<m_name<<",\nsheet:\n";
	int n=0;
	if(hasDelay)
	{
		for(auto & i:m_sheet)
		{
			if(n>6)
			{
				n=0;
				stream<<"\n";
			}
			if(i.first.size()>1)
				//有和弦
				stream<<'('<<i.first<<')'<<QString::number(i.second);
			else
				//没有和弦
				stream<<i.first<<QString::number(i.second);
			++n;
		}
	}
	else
	{
		for(auto & i:m_sheet)
		{
			if(n>6)
			{
				n=0;
				stream<<"\n";
			}
			if(i.first.size()>1)
				//有和弦
				stream<<" ("<<i.first<<") ";
			else
				//没有和弦
				stream<<" "<<i.first<<" ";
			++n;
		}
	}
}



Music::Music(QString author,QString name)
{
	this->m_author=author;
	this->m_name=name;
}

QString Music::toString() const
{
	return "曲名: "+m_name+" 作者: "+m_author;
}

QString Music::getAuthor()const {return  m_author;}
QString Music::getName()const {return m_name;}
QList<std::pair<QString,int>>& Music::getSheet() {return m_sheet;}


//解析琴谱 种类1
bool Music::analyze1(QString& strSheet,int delay)
{
	strSheet=strSheet.toUpper();//忽略大小写
	int d;//延时
	for(int i=0;i<strSheet.size();++i)
	{
		QString m;//按键
		d=0;
		//获取 格式 [100] 延时块 修改默认延时 delay
		if(strSheet[i]=='[')
		{
			int tmp=0;
			while((++i)<strSheet.size()&&strSheet[i]!=']')//字串转数值
				if(strSheet[i].isDigit())
					tmp=tmp*10+strSheet[i].digitValue();
			if(tmp!=0)
				delay=tmp;
		}
		else if(strSheet[i]=='(') //存在和弦
		{
			//找按键
			while((++i)<strSheet.size()&&strSheet[i]!=')')
			{
				if('A'<=strSheet[i]&&strSheet[i]<='Z')
					m.append(strSheet[i]);
			}
			//确定延时  这里只考虑整数
			while(i+1<strSheet.size()&&strSheet[i+1].isDigit())
			{
				++i;
				d=d*10+strSheet[i].digitValue();
			}
		}else  if('A'<=strSheet[i]&&strSheet[i]<='Z') //没有和弦
		{
			m.append(strSheet[i]);
			//确定延时
			while(i+1<strSheet.size()&&strSheet[i+1].isDigit())
			{
				++i;
				d=d*10+strSheet[i].digitValue();
			}
		}else
			continue;//其他字符过滤掉
		if(!m.isEmpty())
		{
			if(d==0)//没有单独设置延时  为默认
				d=delay;
			std::pair<QString,int> p= std::make_pair(m,d);
			m_sheet.append(p);
		}
	}
	return !m_sheet.isEmpty();
}