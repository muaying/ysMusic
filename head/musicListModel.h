#ifndef MUSICLISTMODEL_H
#define MUSICLISTMODEL_H

#include <QAbstractTableModel>
#include "Music.h"

class musicListModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit musicListModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;


	void addMusic(Music& m);
	void deleteMusic(int row);
	QList<std::pair<QString,int>>& getSheet(int row);
private:
	QList<QString> m_headers;
	QList<Music> m_musicList;
};

#endif // MUSICLISTMODEL_H
