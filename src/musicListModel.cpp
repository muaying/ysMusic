#include "musicListModel.h"

musicListModel::musicListModel(QObject *parent)
    : QAbstractTableModel(parent)
{
	m_headers.clear();
	m_headers<<"曲名"<<"作者";
	m_musicList.clear();
	QString status;
	Music* pMusic=Music::createMusic(":/res/sheet/1.txt",status);
	m_musicList.push_back(*pMusic);
	delete pMusic;
	pMusic=Music::createMusic(":/res/sheet/2.txt",status);
	m_musicList.push_back(*pMusic);
	delete pMusic;
	pMusic=Music::createMusic(":/res/sheet/3.txt",status);
	m_musicList.push_back(*pMusic);
	delete pMusic;
}

QVariant musicListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	//qDebug()<<"section"<<section;
	if (orientation == Qt::Horizontal)
	{
		switch (role)
		{
			case Qt::DisplayRole:
				return m_headers[section];
		}
	}
	else
	{
		switch (role)
		{
			case Qt::DisplayRole:
				if(section<m_musicList.size())
					return section+1;
				break;
		}
	}

	return QVariant();
}

int musicListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
	return  m_musicList.size();
}

int musicListModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;
   return m_headers.size();
}

QVariant musicListModel::data(const QModelIndex &index, int role) const
{
	if (!index.isValid())
	{
		return QVariant();
	}

	int nRow = index.row();
	int nCol = index.column();
	if (nRow>= rowCount() || nRow<0 || nCol>= columnCount() || nCol<0)
	{
		return QVariant();
	}
	switch (role)
	{
		case Qt::DisplayRole:
			switch (nCol)
			{
				case 0:
					return m_musicList[nRow].getName();
				case 1:
					return m_musicList[nRow].getAuthor();
			}
			break;
	}
	return QVariant();
}

void musicListModel::addMusic(Music &m)
{
	int nCount = rowCount();
	beginInsertRows(QModelIndex(), nCount,nCount);
	m_musicList.push_back(m);
	endInsertRows();
}

void musicListModel::deleteMusic(int row)
{
	if(row< rowCount())
	{
		beginRemoveRows(QModelIndex(),row,row);

		qDebug()<<"删除行："+QString::number(row)+" music"+m_musicList[row].toString();
		m_musicList.remove(row);

		endRemoveRows();
	}

}

QList<std::pair<QString,int>>& musicListModel::getSheet(int row)
{
		return m_musicList[row].getSheet();
}

const Music &musicListModel::getMusic(int row) const
{
	return m_musicList[row];
}