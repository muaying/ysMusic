#include "helpwindow.h"
#include "ui_helpwindow.h"

HelpWindow::HelpWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::HelpWindow)
{
    ui->setupUi(this);
	connect(ui->pushButton,&QPushButton::clicked,this,[this](){
		close();
	});
}

HelpWindow::~HelpWindow()
{
    delete ui;
}
