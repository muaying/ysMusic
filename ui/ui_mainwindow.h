/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QAction *actionAbout;
    QAction *actionHelp;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_4;
    QPushButton *btnLoad;
    QCheckBox *checkBoxTopWindow;
    QPushButton *btnTest;
    QPushButton *btnResetHotkey;
    QComboBox *cmbHot1;
    QComboBox *cmbHot2;
    QLabel *label;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QTableView *tableView;
    QMenuBar *menubar;
    QMenu *menu_file;
    QMenu *menu_help;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(476, 390);
        MainWindow->setMaximumSize(QSize(500, 390));
        MainWindow->setBaseSize(QSize(430, 330));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QString::fromUtf8("actionLoad"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMinimumSize(QSize(200, 330));
        groupBox_4->setMaximumSize(QSize(16777215, 330));
        btnLoad = new QPushButton(groupBox_4);
        btnLoad->setObjectName(QString::fromUtf8("btnLoad"));
        btnLoad->setGeometry(QRect(70, 120, 91, 24));
        checkBoxTopWindow = new QCheckBox(groupBox_4);
        checkBoxTopWindow->setObjectName(QString::fromUtf8("checkBoxTopWindow"));
        checkBoxTopWindow->setGeometry(QRect(70, 70, 80, 20));
        btnTest = new QPushButton(groupBox_4);
        btnTest->setObjectName(QString::fromUtf8("btnTest"));
        btnTest->setGeometry(QRect(80, 290, 75, 24));
        btnResetHotkey = new QPushButton(groupBox_4);
        btnResetHotkey->setObjectName(QString::fromUtf8("btnResetHotkey"));
        btnResetHotkey->setGeometry(QRect(70, 200, 70, 25));
        btnResetHotkey->setMaximumSize(QSize(70, 25));
        cmbHot1 = new QComboBox(groupBox_4);
        cmbHot1->addItem(QString());
        cmbHot1->addItem(QString());
        cmbHot1->addItem(QString());
        cmbHot1->setObjectName(QString::fromUtf8("cmbHot1"));
        cmbHot1->setGeometry(QRect(30, 240, 48, 22));
        cmbHot1->setMaximumSize(QSize(70, 25));
        cmbHot2 = new QComboBox(groupBox_4);
        cmbHot2->addItem(QString());
        cmbHot2->addItem(QString());
        cmbHot2->addItem(QString());
        cmbHot2->addItem(QString());
        cmbHot2->addItem(QString());
        cmbHot2->addItem(QString());
        cmbHot2->setObjectName(QString::fromUtf8("cmbHot2"));
        cmbHot2->setGeometry(QRect(140, 240, 46, 22));
        cmbHot2->setMaximumSize(QSize(70, 25));
        label = new QLabel(groupBox_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 240, 15, 15));
        label->setMaximumSize(QSize(15, 15));

        horizontalLayout_2->addWidget(groupBox_4);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(200, 330));
        groupBox_3->setMaximumSize(QSize(200, 330));
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableView = new QTableView(groupBox_3);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->horizontalHeader()->setCascadingSectionResizes(true);

        horizontalLayout->addWidget(tableView);


        horizontalLayout_2->addWidget(groupBox_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 476, 22));
        menu_file = new QMenu(menubar);
        menu_file->setObjectName(QString::fromUtf8("menu_file"));
        menu_help = new QMenu(menubar);
        menu_help->setObjectName(QString::fromUtf8("menu_help"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_file->menuAction());
        menubar->addAction(menu_help->menuAction());
        menu_file->addAction(actionLoad);
        menu_help->addAction(actionAbout);
        menu_help->addSeparator();
        menu_help->addAction(actionHelp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\216\237\347\245\236Music", nullptr));
        actionLoad->setText(QCoreApplication::translate("MainWindow", "\344\273\216\346\226\207\344\273\266\344\270\255\350\275\275\345\205\245", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        actionHelp->setText(QCoreApplication::translate("MainWindow", "\344\275\277\347\224\250\345\270\256\345\212\251", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\345\212\237\350\203\275\345\214\272", nullptr));
        btnLoad->setText(QCoreApplication::translate("MainWindow", "\344\273\216\346\226\207\344\273\266\344\270\255\350\275\275\345\205\245", nullptr));
        checkBoxTopWindow->setText(QCoreApplication::translate("MainWindow", "\347\252\227\345\217\243\347\275\256\351\241\266", nullptr));
        btnTest->setText(QCoreApplication::translate("MainWindow", "Test", nullptr));
        btnResetHotkey->setText(QCoreApplication::translate("MainWindow", "\351\207\215\350\256\276\345\256\217\346\214\211\351\224\256", nullptr));
        cmbHot1->setItemText(0, QCoreApplication::translate("MainWindow", "\347\251\272", nullptr));
        cmbHot1->setItemText(1, QCoreApplication::translate("MainWindow", "Ctrl", nullptr));
        cmbHot1->setItemText(2, QCoreApplication::translate("MainWindow", "ALT", nullptr));

        cmbHot2->setItemText(0, QCoreApplication::translate("MainWindow", "\347\251\272", nullptr));
        cmbHot2->setItemText(1, QCoreApplication::translate("MainWindow", "F6", nullptr));
        cmbHot2->setItemText(2, QCoreApplication::translate("MainWindow", "F7", nullptr));
        cmbHot2->setItemText(3, QCoreApplication::translate("MainWindow", "F8", nullptr));
        cmbHot2->setItemText(4, QCoreApplication::translate("MainWindow", "F9", nullptr));
        cmbHot2->setItemText(5, QCoreApplication::translate("MainWindow", "F10", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\347\220\264\350\260\261\345\210\227\350\241\250", nullptr));
        menu_file->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_help->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
