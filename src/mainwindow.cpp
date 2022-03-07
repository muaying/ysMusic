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
	if(MyHook::getMyHook()->install()!=0)
		QMessageBox::warning(this,"错误","Hook注册失败，程序无法正常运行");
	init();
}


void MainWindow::loadFile()
{
	QString filename=QFileDialog::getOpenFileName(this,"选择文件","./","琴谱文件(*.txt)");
	if(!filename.isEmpty())
	{
		try {
			m_musicList.addMusic(Music::createMusic(filename));
		}catch (const char* str)
		{
			QMessageBox::warning(this,"错误",str);
		}
	}
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
	ui->tableView->selectRow(0);
	//右键琴谱功能
	m_pTableMenu=new QMenu(ui->tableView);
	m_pTableDelete =new QAction(m_pTableMenu);
	m_pMusicToFile =new QAction(m_pTableMenu);
	m_pTableDelete->setText("删除");
	m_pTableMenu->addAction(m_pTableDelete);
	m_pMusicToFile->setText("导出");
	m_pTableMenu->addAction(m_pMusicToFile);



	//注册热键
	if (m_Hotkey1.registerKey("F6")&&m_Hotkey2.registerKey("CTRL+F6"))
	{
		ui->cmbHot1->setCurrentIndex(1);
	}else
	{
		QMessageBox::warning(this, "提示", "检测到热键冲突，请手动设置热键");
		m_Hotkey1.unregisterKey();
		m_Hotkey2.unregisterKey();
	}
	ui->checkBoxhasDelay->setCheckState(Qt::Checked);
	connect(ui->btnResetHotkey,&QPushButton::clicked,this,&MainWindow::resetHotKey);
	//槽函数绑定
	connect(this,&MainWindow::doPlay,&this->m_player,&Player::play);

	//播放与暂停
	connect(&this->m_Hotkey1,&MyHotKey::active,[this]()
	{

		if(!m_player.isPlaying())//还没有在播放状态 播放
			emit doPlay(m_musicList.getSheet(ui->tableView->selectionModel()->currentIndex().row()));
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
	connect(&this->m_Hotkey2,&MyHotKey::active,[this](){
		if(m_player.isPlaying())
			m_player.reset();
	});
	connect(ui->tableView,&QTableView::clicked,this,[this]()
	{
		if(m_player.isPlaying())
			m_player.reset();
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
	connect(ui->btnLoad,&QPushButton::clicked,this,&MainWindow::loadFile);
	connect(ui->actionLoad,&QAction::triggered,this,&MainWindow::loadFile);
	connect(ui->btnRecord,&QPushButton::clicked,this,[this](){
		if(ui->btnRecord->text()=="开始录制")
		{
			ui->btnRecord->setText("结束录制");
			MyHook::getMyHook()->beginRecording();
		}
		else
		{
			auto res=MyHook::getMyHook()->endRecording();
			m_musicList.addMusic(Music::createMusic(ui->edtName->text(),ui->edtAuthor->text(),res));
			ui->btnRecord->setText("开始录制");
		}
	});

	//表格右键菜单
	connect(ui->tableView,&QTableView::customContextMenuRequested,this,[this](QPoint point){
		QModelIndex index = ui->tableView->indexAt(point);
		if(index.isValid())
		{
			m_pTableMenu->exec(QCursor::pos());
		}
	});
	//删除功能
	connect(m_pTableDelete,&QAction::triggered,this,[this](){
		QModelIndex index = ui->tableView->currentIndex();
		if(index.isValid()&&index.row()>2)
			m_musicList.deleteMusic(index.row());
	});
	//导出琴谱
	connect(m_pMusicToFile,&QAction::triggered,this,[this](){
		QModelIndex index = ui->tableView->currentIndex();
		if(index.isValid())
		{
			QString dir=QFileDialog::getExistingDirectory(this,"选中保存路径","./");
			dir=dir+'/'+m_musicList.getMusic(index.row()).getName()+".txt";
			QFile file(dir);
			if(file.open(QIODevice::WriteOnly|QIODevice::Text))
			{
				QTextStream stream(&file);
				m_musicList.getMusic(index.row()).toFile(stream,ui->checkBoxhasDelay->checkState()==Qt::Checked);
				file.close();
			}else
				QMessageBox::warning(this, "提示", "无法新建文件");

		}
	});
}



void MainWindow::resetHotKey()
{
    QString key = ui->cmbHot1->currentText();
    m_Hotkey1.unregisterKey();
	m_Hotkey1.unregisterKey();
    if (key == "空")
        QMessageBox::warning(this, "警告", "请选择合适的热键");
	else
	{

		if (m_Hotkey1.registerKey(key)&&m_Hotkey2.registerKey("CTRL+"+key))
		{
			QMessageBox::warning(this, "提示", "热键重设成功");
		}
		else
		{
			QMessageBox::warning(this, "提示", "检测到热键冲突，请重新设置热键");
			ui->cmbHot1->setCurrentText("空");
			m_Hotkey1.unregisterKey();
			m_Hotkey1.unregisterKey();
		}
	}
}

MainWindow::~MainWindow()
{
	m_player.setFlag(false);
    m_pThread->quit();
	m_pThread->wait();
	MyHook::getMyHook()->uninstall();
    delete ui;
}



void MainWindow::about()
{
	QMessageBox::about(this,"关于",
					   R"(作者：越行勤
程序简介：原神简易弹琴助手
版本：1.6
博客：blog.yxqin.top
项目地址：https://gitee.com/yuexingqin/ysMusic)");
}