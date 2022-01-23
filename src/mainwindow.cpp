#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <utility>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{

    //初始化 ui
    setWindowIcon(QIcon(":/res/imgs/miao.png"));
    ui->setupUi(this);
    ui->spbDelay->setValue(50);
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
    //初始化 弹琴
    playOk = false;
    thread = new QThread(this);
    player.moveToThread(thread);
    thread->start();
    //槽函数绑定
    //重设热键
    connect(ui->btnResetHotkey, &QPushButton::clicked, this, &MainWindow::resetHotKey);
    connect(ui->btnReadPlay, &QPushButton::clicked, this, &MainWindow::readPlay);
    connect(this, &MainWindow::doPlay, &player, &Player::play);
	connect(ui->btnSelect,&QPushButton::clicked,this,[this](){
		QString  t= QFileDialog::getOpenFileName(this,"选择乐谱","./", tr("乐谱文件 (*.txt)"));
		if(!t.isEmpty())
		{
			fileName=t;
			QMessageBox::information(this,"提示","选择文件成功");

		}
	});
    connect(qHotkey, &QHotkey::activated, this, [this]()
    {
        if (playOk == true)
        {
            if (player.isPlaying())
            {
                player.setPlayFlag(false);
            } else
            {
                player.setPlayFlag(true);
                emit doPlay(musics, ui->spbDelay->value());
            }
        }
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
    player.setPlayFlag(false);
    thread->quit();
    thread->wait();
    delete ui;
}

void MainWindow::readPlay()
{
    if (fileName.isEmpty())
        fileName = ":/res/sheet/" + ui->cmbSelect->currentText() + ".txt";
    QFile qFile(fileName);
    if (!qFile.open(QFile::ReadOnly))
    {
        QMessageBox::warning(this, "错误", "打开文件失败");
    } else
    {
        try
        {
            QByteArray data = qFile.readAll();
            qFile.close();
            //获取 作者 曲名 以及  曲谱
            QString sheet;
            QByteArray buf;
            for (auto it = data.cbegin(); it < data.cend(); ++it)
            {

                if (*it == ' ' || *it == '\n' || *it == '\r')
                {
                    continue;
                } else if (*it == ':')
                {
                    QByteArray tmp;
                    while (*it != ',' && it != data.cend() && *it != '\x00')
                    {
                        ++it;
                        if (*it == ' ' || *it == '\n' || *it == '\r' || *it == ',' || *it == '\x00')
                            continue;
                        tmp.append(*it);
                    }
                    if (buf == "author")
                        this->ui->editAuthor->setText(tmp);
                    else if (buf == "musicName")
                        this->ui->editMusicName->setText(tmp);
                    else if (buf == "delay")
                    {
                        bool ok;
                        int val = tmp.toInt(&ok);
                        if (ok)
                            this->ui->spbDelay->setValue(val);
                    } else if (buf == "sheet")
                        sheet = tmp;
                    buf.clear();
                } else
                    buf.append(*it);
            }
            if (!sheet.isEmpty())
            {
				musics.clear();
				sheet=sheet.toUpper();
                //解析琴谱
				for(int i=0;i<sheet.size();++i)
				{
					QString m;//按键
					int d=1;//延时
					if(sheet[i]=='(') //存在和弦
					{
						//找按键
						while(sheet[(++i)]!=')'&&i<sheet.size())
						{
							if('A'<=sheet[i]&&sheet[i]<='Z')
								m.append(sheet[i]);
						}
						++i;
						if( i<sheet.size()&&sheet[i]>='1'&&sheet[i]<='9')
							d=QString(sheet[i]).toInt();
						else
							--i;
					}else  if('A'<=sheet[i]&&sheet[i]<='Z') //没有和弦
					{
						m.append(sheet[i]);
						//确定延时
						++i;
						if( i<sheet.size()&&sheet[i]>='1'&&sheet[i]<='9')
							d=QString(sheet[i]).toInt();
						else
							--i;
					}else
						;
					if(!m.isEmpty())
					{
						std::pair<QString,int> p= std::make_pair(m,d);
						musics.append(p);
					}
				}
            }
            playOk = true;
        }
        catch (std::exception e)
        {
            QMessageBox::warning(this, "错误", "无法解析该琴谱,请检查格式");
            playOk = false;
        }
        QMessageBox::information(this, "提示", "请在原神中使用[琴],再按下热键[" + qHotkey->shortcut().toString() + "] 弹琴,再次按下停止演奏");
    }

}