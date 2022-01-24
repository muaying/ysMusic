#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qhotkey.h>
#include <QThread>
#include "Player.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private slots:
	void resetHotKey();

    signals:
            void doPlay(QList <std::pair<QString, int>> music,int delay);

private:
	void readPlay();
	bool loadSheet(QString filename);
private:
    Ui::MainWindow *ui;
    QHotkey *qHotkey;
    Player player;
    QThread *thread;
    //琴谱 文件名字
    QString fileName;
    //琴谱
	QList <std::pair<QString, int>> musics;

};

#endif // MAINWINDOW_H
