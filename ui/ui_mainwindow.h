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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
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
    QPushButton *btnTest;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkBoxTopWindow;
    QPushButton *btnLoad;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnResetHotkey;
    QHBoxLayout *horizontalLayout_4;
    QComboBox *cmbHot1;
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
        MainWindow->resize(500, 390);
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
        btnTest = new QPushButton(groupBox_4);
        btnTest->setObjectName(QString::fromUtf8("btnTest"));
        btnTest->setGeometry(QRect(30, 230, 75, 24));
        layoutWidget = new QWidget(groupBox_4);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 40, 197, 66));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        checkBoxTopWindow = new QCheckBox(layoutWidget);
        checkBoxTopWindow->setObjectName(QString::fromUtf8("checkBoxTopWindow"));

        horizontalLayout_5->addWidget(checkBoxTopWindow);

        btnLoad = new QPushButton(layoutWidget);
        btnLoad->setObjectName(QString::fromUtf8("btnLoad"));

        horizontalLayout_5->addWidget(btnLoad);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btnResetHotkey = new QPushButton(layoutWidget);
        btnResetHotkey->setObjectName(QString::fromUtf8("btnResetHotkey"));
        btnResetHotkey->setMaximumSize(QSize(70, 25));

        horizontalLayout_3->addWidget(btnResetHotkey);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        cmbHot1 = new QComboBox(layoutWidget);
        cmbHot1->addItem(QString());
        cmbHot1->addItem(QString());
        cmbHot1->addItem(QString());
        cmbHot1->addItem(QString());
        cmbHot1->addItem(QString());
        cmbHot1->addItem(QString());
        cmbHot1->addItem(QString());
        cmbHot1->addItem(QString());
        cmbHot1->setObjectName(QString::fromUtf8("cmbHot1"));
        cmbHot1->setMaximumSize(QSize(70, 25));

        horizontalLayout_4->addWidget(cmbHot1);


        horizontalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_2->addWidget(groupBox_4);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(250, 330));
        groupBox_3->setMaximumSize(QSize(260, 330));
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        tableView = new QTableView(groupBox_3);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setSelectionMode(QAbstractItemView::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->horizontalHeader()->setCascadingSectionResizes(true);

        horizontalLayout->addWidget(tableView);


        horizontalLayout_2->addWidget(groupBox_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 500, 22));
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
        btnTest->setText(QCoreApplication::translate("MainWindow", "Test", nullptr));
        checkBoxTopWindow->setText(QCoreApplication::translate("MainWindow", "\347\252\227\345\217\243\347\275\256\351\241\266", nullptr));
        btnLoad->setText(QCoreApplication::translate("MainWindow", "\344\273\216\346\226\207\344\273\266\344\270\255\350\275\275\345\205\245", nullptr));
        btnResetHotkey->setText(QCoreApplication::translate("MainWindow", "\351\207\215\350\256\276\345\256\217\346\214\211\351\224\256", nullptr));
        cmbHot1->setItemText(0, QCoreApplication::translate("MainWindow", "\347\251\272", nullptr));
        cmbHot1->setItemText(1, QCoreApplication::translate("MainWindow", "F6", nullptr));
        cmbHot1->setItemText(2, QCoreApplication::translate("MainWindow", "F7", nullptr));
        cmbHot1->setItemText(3, QCoreApplication::translate("MainWindow", "F8", nullptr));
        cmbHot1->setItemText(4, QCoreApplication::translate("MainWindow", "F9", nullptr));
        cmbHot1->setItemText(5, QCoreApplication::translate("MainWindow", "F10", nullptr));
        cmbHot1->setItemText(6, QCoreApplication::translate("MainWindow", "F11", nullptr));
        cmbHot1->setItemText(7, QCoreApplication::translate("MainWindow", "F12", nullptr));

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
