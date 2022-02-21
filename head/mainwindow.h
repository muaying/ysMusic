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
    QHotkey *m_pHotkey1;//热键1 开始和停止
	QHotkey *m_pHotkey2;//热键2 暂停
    Player m_player;
    QThread *m_pThread;
	musicListModel m_musicList;
	HelpWindow* m_pHelpWindow;
	QMenu* m_pTableMenu;//tableView 右键菜单
	QAction* m_pTableDelete;//tableView 删除功能键
};

#endif // MAINWINDOW_H
