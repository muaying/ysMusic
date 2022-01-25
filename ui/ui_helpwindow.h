/********************************************************************************
** Form generated from reading UI file 'helpwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPWINDOW_H
#define UI_HELPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelpWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *textEdit_2;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HelpWindow)
    {
        if (HelpWindow->objectName().isEmpty())
            HelpWindow->setObjectName(QString::fromUtf8("HelpWindow"));
        HelpWindow->resize(451, 495);
        HelpWindow->setMinimumSize(QSize(450, 495));
        HelpWindow->setMaximumSize(QSize(16777215, 16777215));
        centralwidget = new QWidget(HelpWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        textEdit_2 = new QTextEdit(groupBox_2);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        verticalLayout_2->addWidget(textEdit_2);


        gridLayout->addWidget(groupBox_2, 1, 0, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);

        HelpWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(HelpWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 451, 22));
        HelpWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(HelpWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HelpWindow->setStatusBar(statusbar);

        retranslateUi(HelpWindow);

        QMetaObject::connectSlotsByName(HelpWindow);
    } // setupUi

    void retranslateUi(QMainWindow *HelpWindow)
    {
        HelpWindow->setWindowTitle(QCoreApplication::translate("HelpWindow", "\345\270\256\345\212\251", nullptr));
        groupBox->setTitle(QCoreApplication::translate("HelpWindow", "\344\275\277\347\224\250\350\257\264\346\230\216", nullptr));
        textEdit->setHtml(QCoreApplication::translate("HelpWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\344\275\277\347\224\250\346\255\245\351\252\244\357\274\232</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1. \347\256\241\347\220\206\345\221\230\350\272\253\344\273\275\345\220\257\345\212\250\347\250\213\345\272\217\357\274\214<span style=\" font-weight:700;\">\344\270\200\345\256\232\350\246\201\346\230\257\347\256\241\347\220\206\345\221\230</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-"
                        "block-indent:0; text-indent:0px;\">2. \350\256\276\347\275\256\347\203\255\351\224\256(\351\273\230\350\256\244\350\256\276\347\275\256F6)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">3. \351\200\211\346\213\251\347\220\264\350\260\261(\351\273\230\350\256\244\351\200\211\346\213\251\347\220\264\350\260\2611)\357\274\214\344\271\237\345\217\257\344\273\245\350\275\275\345\205\245\350\207\252\345\256\232\344\271\211\347\220\264\350\260\261</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">4. \350\275\275\345\205\245\347\220\264\350\260\261</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">4. \350\277\233\345\205\245\346\270\270\346\210\217\357\274\214\344\275\277\347\224\250\350\277\233\345\216\273\345\274\271\347\220\264\347\225\214\351\235\242</p>\n"
"<p style=\" margin-t"
                        "op:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">5. \346\214\211\344\270\213\347\203\255\351\224\256\357\274\214\345\274\200\345\247\213\345\274\271\347\220\264\357\274\214\345\206\215\346\254\241\346\214\211\344\270\213\344\270\255\346\226\255\345\274\271\345\245\217</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">PS: \347\250\213\345\272\217\345\220\257\345\212\250\350\207\252\345\212\250\350\275\275\345\205\245\344\272\206\347\220\264\350\260\2611\357\274\214\346\214\211\344\270\213\347\203\255\351\224\256\345\217\257\344\273\245\345\274\200\345\247\213\345\274\271\345\245\217\357\274\233\350\275\275\345\205\245\345\244\261\350\264\245\357\274\214\345\275\223\345\211\215\347\220\264\350\260\261\344\273\215\344\270\272\344"
                        "\270\212\346\254\241\350\275\275\345\205\245\346\210\220\345\212\237\347\232\204\347\220\264\350\260\261</p></body></html>", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("HelpWindow", "\347\220\264\350\260\261\346\226\207\344\273\266\350\257\264\346\230\216", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("HelpWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\347\244\272\344\276\213\347\220\264\350\260\261\346\226\207\344\273\266</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">author : \344\275\234\350\200\205\345\220\215 ,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:"
                        "0px;\">musicName : \346\233\262\345\220\215 ,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">delay:\345\273\266\346\227\266,</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">sheet : </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">F6 (FA)6</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">author,musicName,delay \344\270\215\346\230\257\345\277\205\351\241\273\347\232\204,\344\275\206\346\230\257sheet\346\230\257\345\277\205\351\241\273\347\232\204\343\200\202</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin"
                        "-right:0px; -qt-block-indent:0; text-indent:0px;\">PS:</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1. \346\257\217\344\270\252\345\261\236\346\200\247\345\277\205\351\241\273\346\230\257 [&lt;\345\261\236\346\200\247&gt; : \345\206\205\345\256\271 ,] <span style=\" font-weight:700;\"> \345\206\222\345\217\267\351\200\227\345\217\267\351\203\275\344\270\215\345\217\257\345\260\221\357\274\214\344\270\224\351\203\275\346\230\257\345\215\212\350\247\222\347\254\246\345\217\267\343\200\202sheet\346\234\200\345\220\216\346\227\240\351\234\200\350\267\237 \351\200\227\345\217\267\346\240\207\350\256\260\347\273\223\346\235\237 </span> </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">2. delay \346\230\257 \351\273\230\350\256\244 \345\273\266\346\227\266\357\274\214\344\271\237\345\260\261\346\230\257\344\270\200\344\270\252\346\214\211\351\224\256\347\274"
                        "\272\347\234\201\347\212\266\346\200\201\344\270\213\347\232\204\345\273\266\346\227\266\343\200\202\350\257\245\345\261\236\346\200\247\347\274\272\347\234\201\357\274\214\345\210\231\344\270\272100ms</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">sheet \350\257\264\346\230\216:</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">sheet\346\240\207\350\256\260\347\220\264\350\260\261\347\232\204\345\274\200\345\247\213\357\274\214</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1. F6 \350\241\250\347\244\272\346\214\211\344\270\213 F \351\224\256 \357\274\2146ms\345\273\266\346\227\266</p>\n"
"<p style=\" margin-top:"
                        "0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">2. (FA)6 \350\241\250\347\244\272\345\220\214\346\227\266\346\214\211\344\270\213 FA 6ms\345\273\266\346\227\266</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">3. \345\237\272\346\234\254\346\240\274\345\274\217\344\270\272 [key] [\345\273\266\346\227\266,\345\215\225\344\275\215\346\257\253\347\247\222] \357\274\214()\346\212\261\350\265\267\346\235\245\347\232\204\345\244\232\344\270\252key\350\241\250\347\244\272\345\220\214\346\227\266\346\214\211\344\270\213, [\345\273\266\346\227\266]\345\217\257\344\273\245\347\274\272\347\234\201\357\274\214</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">4. \346\227\240\350\247\206\347\251\272\346\240\274\346\215\242\350\241\214</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; marg"
                        "in-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("HelpWindow", "\346\210\221\345\267\262\344\272\206\350\247\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelpWindow: public Ui_HelpWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPWINDOW_H
