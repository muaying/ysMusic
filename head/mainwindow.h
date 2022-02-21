#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qhotkey.h>
#include <QThread>
#include "Player.h"
#include "helpwindow.h"
#include "musicListModel.h"
#include <QMenu>
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
	void about();
    signals:
            void doPlay(QList <std::pair<QString, int>>& music);

private:
	//初始化工作 信号连接工作
	void init();
private:
    Ui::MainWindow *ui;
    QHotkey *qHotkey;
    Player player;
    QThread *thread;
	musicListModel musicList;
	HelpWindow* helpWindow;
	QMenu* tableMenu;
	QAction* tableDelte;
};

#endif // MAINWINDOW_H
