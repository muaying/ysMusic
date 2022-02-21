#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    setWindowIcon(QIcon(":/res/imgs/miao.png"));
    ui->setupUi(this);
	init();
}

void MainWindow::init()
{
	helpWindow=new HelpWindow(this);
	//线程创建
	thread=new QThread(this);
	thread->start();
	player.moveToThread(thread);
	//设置表格
	ui->tableView->setModel(&this->musicList);
	ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter);
	ui->tableView->setAlternatingRowColors(true);
	ui->tableView->horizontalHeader()->setStretchLastSection(true);
	ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
	//右键删除琴谱功能
	tableMenu=new QMenu(ui->tableView);
	tableDelte =new QAction(tableMenu);
	tableDelte->setText("删除");
	tableMenu->addAction(tableDelte);
	ui->tableView->selectRow(0);
	//注册热键
	qHotkey = new QHotkey(QKeySequence("F6"), false, this);
	if (!qHotkey->setRegistered(true))
	{
		QMessageBox::warning(this, "提示", "检测到热键冲突，请重新设置热键");
		ui->cmbHot1->setCurrentText("空");
		ui->cmbHot2->setCurrentText("空");
	} else
	{
		ui->cmbHot1->setCurrentText("空");
		ui->cmbHot2->setCurrentText("F6");
	}
	connect(ui->btnResetHotkey,&QPushButton::clicked,this,&MainWindow::resetHotKey);
	//槽函数绑定
	connect(this,&MainWindow::doPlay,&this->player,&Player::play);

	connect(this->qHotkey,&QHotkey::activated,[this]()
	{
		if(!player.isPlaying())
		{
			player.setPause(false);
			player.setFlag(true);
			int nCur=ui->tableView->selectionModel()->currentIndex().row();
			emit doPlay(musicList.getSheet(nCur));
		}else
			player.setFlag(false);
	});

	connect(ui->actionAbout,&QAction::triggered,this,&MainWindow::about);
	connect(ui->actionHelp,&QAction::triggered,this,[this](){
		helpWindow->show();
	});
	connect(ui->btnLoad,&QPushButton::clicked,this,[this](){
		QString filename=QFileDialog::getOpenFileName(this,"选择文件","./","琴谱文件(*.txt)");
		if(!filename.isEmpty())
		{
			QString status;
			Music* m=Music::createMusic(filename,status);
			if(m== nullptr)
				QMessageBox::warning(this, "错误", "载入失败，原因："+status);
			else
			{
				musicList.addMusic(*m);
				delete m;
			}
		}
	});
	connect(ui->btnTest,&QPushButton::clicked,this,[this](){
		QString status;
		Music* pMusic=Music::createMusic(":/res/sheet/1.txt",status);
		if(pMusic!= nullptr)
		{
			musicList.addMusic(*pMusic);
			delete pMusic;
		}else
			QMessageBox::warning(this, "错误", "载入失败，原因："+status);
	});

	//表格右键菜单
	connect(ui->tableView,&QTableView::customContextMenuRequested,this,[this](QPoint point){
		QModelIndex index = ui->tableView->indexAt(point);
		if(index.isValid()&&index.row()>1)
		{
			tableMenu->exec(QCursor::pos());
		}
	});
	//删除功能
	connect(tableDelte,&QAction::triggered,this,[this](){
		QModelIndex index = ui->tableView->currentIndex();
		if(index.isValid())
			musicList.deleteMusic(index.row());
	});
}



void MainWindow::resetHotKey()
{
    QString hot1 = ui->cmbHot1->currentText();
    QString hot2 = ui->cmbHot2->currentText();
    qHotkey->setRegistered(false);
    if (hot2 == "空" && hot1 == "空")
        QMessageBox::warning(this, "警告", "请选择合适的热键");
    if (hot1 == "空")
        qHotkey->setShortcut(QKeySequence(hot2), false);
    else
        qHotkey->setShortcut(QKeySequence(hot1 + '+' + hot2), false);
    if (qHotkey->setRegistered(true))
        QMessageBox::information(this, "提示", "重设热键成功");
    else
    {
        QMessageBox::warning(this, "提示", "检测到热键冲突，请重新设置热键");
        ui->cmbHot1->setCurrentText("空");
        ui->cmbHot2->setCurrentText("空");
    }
}

MainWindow::~MainWindow()
{
    thread->quit();
    thread->wait();
    delete ui;
}



void MainWindow::about()
{
	QMessageBox::about(this,"关于",
					   R"(作者：越行勤
程序简介：原神简易弹琴助手
版本：1.2
博客：blog.yxqin.top
项目地址：https://gitee.com/yuexingqin/ysMusic)");
}