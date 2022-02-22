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
	m_pHelpWindow=new HelpWindow(this);
	//线程创建
	m_pThread=new QThread(this);
	m_pThread->start();
	m_player.moveToThread(m_pThread);
	//设置表格
	ui->tableView->setModel(&this->m_musicList);
	ui->tableView->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter);
	ui->tableView->setAlternatingRowColors(true);
	ui->tableView->horizontalHeader()->setStretchLastSection(true);
	ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
	//右键删除琴谱功能
	m_pTableMenu=new QMenu(ui->tableView);
	m_pTableDelete =new QAction(m_pTableMenu);
	m_pTableDelete->setText("删除");
	m_pTableMenu->addAction(m_pTableDelete);
	ui->tableView->selectRow(0);



	//注册热键
	m_pHotkey1 = new QHotkey(QKeySequence("F6"), false, this);
	m_pHotkey2= new QHotkey(QKeySequence("ctrl+F6"), false, this);
	if (!m_pHotkey1->setRegistered(true)or!m_pHotkey2->setRegistered(true))
	{
		QMessageBox::warning(this, "提示", "检测到热键冲突，请手动设置热键");
		m_pHotkey2->setRegistered(false);
		m_pHotkey1->setRegistered(false);
	}else
		ui->cmbHot1->setCurrentIndex(1);
	connect(ui->btnResetHotkey,&QPushButton::clicked,this,&MainWindow::resetHotKey);
	//槽函数绑定
	connect(this,&MainWindow::doPlay,&this->m_player,&Player::play);

	//播放与暂停
	connect(this->m_pHotkey1,&QHotkey::activated,[this]()
	{

		if(!m_player.isPlaying())//还没有在播放状态 播放
		{
			m_player.setPause(false);
			m_player.setFlag(true);
			emit doPlay(m_musicList.getSheet(ui->tableView->selectionModel()->currentIndex().row()));
		}
		else
		{
			//控制暂停
			if(!m_player.isPause())
				m_player.setPause(true);
			else
				m_player.setPause(false);
		}

	});
	//结束播放
	connect(this->m_pHotkey2,&QHotkey::activated,[this](){
		if(m_player.isPlaying())
		{
			m_player.setFlag(false);
			QThread::msleep(10);
		}
	});
	connect(ui->actionAbout,&QAction::triggered,this,&MainWindow::about);
	connect(ui->checkBoxTopWindow,&QCheckBox::stateChanged,this,[this](int flag){
		if(flag==2)
			//窗口置顶
		{
			this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);
			this->show();
		}
		else if(flag==0)
			//取消置顶
		{
			this->setWindowFlags( this->windowFlags() & ~Qt::WindowStaysOnTopHint);
			this->show();
		}
	});
	connect(ui->actionHelp,&QAction::triggered,this,[this](){
		m_pHelpWindow->show();
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
				if(!m_musicList.addMusic(*m))
					QMessageBox::warning(this, "提示", "当前歌曲已存在");
				delete m;
			}
		}
	});
	connect(ui->btnTest,&QPushButton::clicked,this,[this](){
		QString status;
		Music* pMusic=Music::createMusic(":/res/sheet/1.txt",status);
		if(pMusic!= nullptr)
		{
			if(!m_musicList.addMusic(*pMusic))
				QMessageBox::warning(this, "提示", "当前歌曲已存在");
			delete pMusic;
		}else
			QMessageBox::warning(this, "错误", "载入失败，原因："+status);
	});

	//表格右键菜单
	connect(ui->tableView,&QTableView::customContextMenuRequested,this,[this](QPoint point){
		QModelIndex index = ui->tableView->indexAt(point);
		if(index.isValid()&&index.row()>1)
		{
			m_pTableMenu->exec(QCursor::pos());
		}
	});
	//删除功能
	connect(m_pTableDelete,&QAction::triggered,this,[this](){
		QModelIndex index = ui->tableView->currentIndex();
		if(index.isValid())
			m_musicList.deleteMusic(index.row());
	});
}



void MainWindow::resetHotKey()
{
    QString key = ui->cmbHot1->currentText();
    m_pHotkey1->setRegistered(false);
	m_pHotkey2->setRegistered(false);
    if (key == "空")
        QMessageBox::warning(this, "警告", "请选择合适的热键");
	else
	{
		m_pHotkey1 = new QHotkey(QKeySequence(key), false, this);
		m_pHotkey2= new QHotkey(QKeySequence("ctrl+"+key), false, this);

		if (m_pHotkey1->setRegistered(true)&&m_pHotkey2->setRegistered(true))
			QMessageBox::information(this, "提示", "重设热键成功");
		else
		{
			QMessageBox::warning(this, "提示", "检测到热键冲突，请重新设置热键");
			ui->cmbHot1->setCurrentText("空");
			m_pHotkey1->setRegistered(false);
			m_pHotkey2->setRegistered(false);
		}
	}
}

MainWindow::~MainWindow()
{
	m_player.setFlag(false);
    m_pThread->quit();
	m_pThread->wait();
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