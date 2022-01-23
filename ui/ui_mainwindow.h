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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionAbout;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QLabel *label_2;
    QSpinBox *spbDelay;
    QComboBox *cmbSelect;
    QLabel *label_3;
    QPushButton *btnSelect;
    QGroupBox *groupBox_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *editAuthor;
    QLineEdit *editMusicName;
    QPushButton *btnReadPlay;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnResetHotkey;
    QComboBox *cmbHot1;
    QLabel *label;
    QComboBox *cmbHot2;
    QMenuBar *menubar;
    QMenu *menu_file;
    QMenu *menu_help;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(430, 367);
        MainWindow->setMaximumSize(QSize(430, 400));
        MainWindow->setBaseSize(QSize(430, 330));
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 196));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 110, 91, 16));
        spbDelay = new QSpinBox(groupBox_2);
        spbDelay->setObjectName(QString::fromUtf8("spbDelay"));
        spbDelay->setGeometry(QRect(120, 110, 42, 22));
        spbDelay->setMaximum(20000);
        cmbSelect = new QComboBox(groupBox_2);
        cmbSelect->addItem(QString());
        cmbSelect->setObjectName(QString::fromUtf8("cmbSelect"));
        cmbSelect->setGeometry(QRect(90, 20, 81, 22));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 20, 53, 16));
        btnSelect = new QPushButton(groupBox_2);
        btnSelect->setObjectName(QString::fromUtf8("btnSelect"));
        btnSelect->setGeometry(QRect(10, 60, 171, 24));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(210, 10, 191, 131));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 30, 53, 16));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(20, 70, 53, 16));
        editAuthor = new QLineEdit(groupBox_3);
        editAuthor->setObjectName(QString::fromUtf8("editAuthor"));
        editAuthor->setEnabled(false);
        editAuthor->setGeometry(QRect(60, 30, 113, 21));
        editMusicName = new QLineEdit(groupBox_3);
        editMusicName->setObjectName(QString::fromUtf8("editMusicName"));
        editMusicName->setEnabled(false);
        editMusicName->setGeometry(QRect(60, 70, 113, 21));
        btnReadPlay = new QPushButton(groupBox_2);
        btnReadPlay->setObjectName(QString::fromUtf8("btnReadPlay"));
        btnReadPlay->setGeometry(QRect(150, 160, 75, 24));

        verticalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 132));
        horizontalLayout_2 = new QHBoxLayout(groupBox);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        btnResetHotkey = new QPushButton(groupBox);
        btnResetHotkey->setObjectName(QString::fromUtf8("btnResetHotkey"));
        btnResetHotkey->setMaximumSize(QSize(70, 25));

        horizontalLayout_2->addWidget(btnResetHotkey);

        cmbHot1 = new QComboBox(groupBox);
        cmbHot1->addItem(QString());
        cmbHot1->addItem(QString());
        cmbHot1->addItem(QString());
        cmbHot1->setObjectName(QString::fromUtf8("cmbHot1"));
        cmbHot1->setMaximumSize(QSize(70, 25));

        horizontalLayout_2->addWidget(cmbHot1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(15, 15));

        horizontalLayout_2->addWidget(label);

        cmbHot2 = new QComboBox(groupBox);
        cmbHot2->addItem(QString());
        cmbHot2->addItem(QString());
        cmbHot2->addItem(QString());
        cmbHot2->addItem(QString());
        cmbHot2->addItem(QString());
        cmbHot2->addItem(QString());
        cmbHot2->setObjectName(QString::fromUtf8("cmbHot2"));
        cmbHot2->setMaximumSize(QSize(70, 25));

        horizontalLayout_2->addWidget(cmbHot2);


        verticalLayout->addWidget(groupBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 430, 22));
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
        menu_file->addAction(actionOpen);
        menu_help->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\216\237\347\245\236Music", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow",
                                                        "\344\273\216\346\226\207\344\273\266\344\270\255\351\200\211\346\213\251",
                                                        nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\345\274\271\345\245\217", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow",
                                                     "\345\237\272\347\241\200\345\273\266\346\227\266(ms)\357\274\232",
                                                     nullptr));
        cmbSelect->setItemText(0, QCoreApplication::translate("MainWindow", "test", nullptr));

        label_3->setText(
                QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\344\271\220\350\260\261", nullptr));
        btnSelect->setText(QCoreApplication::translate("MainWindow",
                                                       "\344\273\216\346\226\207\344\273\266\344\270\255\351\200\211\346\213\251",
                                                       nullptr));
        groupBox_3->setTitle(
                QCoreApplication::translate("MainWindow", "\344\271\220\350\260\261\344\277\241\346\201\257", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\344\275\234\350\200\205", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\346\233\262\345\220\215\357\274\232", nullptr));
        btnReadPlay->setText(
                QCoreApplication::translate("MainWindow", "\344\277\235\345\255\230\350\256\276\347\275\256", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow",
                                                       "\345\256\217\346\214\211\351\224\256\350\256\276\347\275\256",
                                                       nullptr));
        btnResetHotkey->setText(QCoreApplication::translate("MainWindow",
                                                            "\351\207\215\350\256\276\345\256\217\346\214\211\351\224\256",
                                                            nullptr));
        cmbHot1->setItemText(0, QCoreApplication::translate("MainWindow", "\347\251\272", nullptr));
        cmbHot1->setItemText(1, QCoreApplication::translate("MainWindow", "Ctrl", nullptr));
        cmbHot1->setItemText(2, QCoreApplication::translate("MainWindow", "ALT", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        cmbHot2->setItemText(0, QCoreApplication::translate("MainWindow", "\347\251\272", nullptr));
        cmbHot2->setItemText(1, QCoreApplication::translate("MainWindow", "F6", nullptr));
        cmbHot2->setItemText(2, QCoreApplication::translate("MainWindow", "F7", nullptr));
        cmbHot2->setItemText(3, QCoreApplication::translate("MainWindow", "F8", nullptr));
        cmbHot2->setItemText(4, QCoreApplication::translate("MainWindow", "F9", nullptr));
        cmbHot2->setItemText(5, QCoreApplication::translate("MainWindow", "F10", nullptr));

        menu_file->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_help->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui
{
    class MainWindow : public Ui_MainWindow
    {
    };
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
