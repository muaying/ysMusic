#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qhotkey.h>
#include <QThread>
#include "Player.h"
#include "helpwindow.h"
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
	void readPlay();
	void about();
    signals:
            void doPlay(QList <std::pair<QString, int>> music);

private:
	QList <std::pair<QString, int>> loadSheet(QString filename);
private:
    Ui::MainWindow *ui;
    QHotkey *qHotkey;
    Player player;
    QThread *thread;
    //琴谱 文件名字
    QString fileName;
    //琴谱
	QList <std::pair<QString, int>> musics;
	HelpWindow* helpWindow;
};

#endif // MAINWINDOW_H
