/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainWindow
{
public:
    QWidget *centralwindow;
    QHBoxLayout *horizontalLayout_7;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QWidget *widget_31;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *ipLineEdit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *portLineEdit;
    QPushButton *connBtn;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_5;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QTextEdit *sendTextEdit;
    QPushButton *sendBtn;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_2;
    QListWidget *recvListWidget;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_4;
    QListWidget *listWidget;
    QToolBar *toolBar;

    void setupUi(QMainWindow *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName(QString::fromUtf8("mainWindow"));
        mainWindow->resize(1044, 796);
        centralwindow = new QWidget(mainWindow);
        centralwindow->setObjectName(QString::fromUtf8("centralwindow"));
        horizontalLayout_7 = new QHBoxLayout(centralwindow);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        widget_3 = new QWidget(centralwindow);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        verticalLayout_3 = new QVBoxLayout(widget_3);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        groupBox_3 = new QGroupBox(widget_3);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(16777215, 400));
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        widget_31 = new QWidget(groupBox_3);
        widget_31->setObjectName(QString::fromUtf8("widget_31"));
        horizontalLayout_2 = new QHBoxLayout(widget_31);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget_31);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        ipLineEdit = new QLineEdit(widget_31);
        ipLineEdit->setObjectName(QString::fromUtf8("ipLineEdit"));

        horizontalLayout_2->addWidget(ipLineEdit);


        verticalLayout_5->addWidget(widget_31);

        widget = new QWidget(groupBox_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        portLineEdit = new QLineEdit(widget);
        portLineEdit->setObjectName(QString::fromUtf8("portLineEdit"));

        horizontalLayout->addWidget(portLineEdit);


        verticalLayout_5->addWidget(widget);

        connBtn = new QPushButton(groupBox_3);
        connBtn->setObjectName(QString::fromUtf8("connBtn"));

        verticalLayout_5->addWidget(connBtn);


        verticalLayout_3->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(widget_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setMaximumSize(QSize(16777215, 100));
        horizontalLayout_5 = new QHBoxLayout(groupBox_4);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        widget_2 = new QWidget(groupBox_4);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setMaximumSize(QSize(16777215, 100));
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        sendTextEdit = new QTextEdit(widget_2);
        sendTextEdit->setObjectName(QString::fromUtf8("sendTextEdit"));

        horizontalLayout_4->addWidget(sendTextEdit);

        sendBtn = new QPushButton(widget_2);
        sendBtn->setObjectName(QString::fromUtf8("sendBtn"));

        horizontalLayout_4->addWidget(sendBtn);


        horizontalLayout_5->addWidget(widget_2);


        verticalLayout_3->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(widget_3);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_2 = new QVBoxLayout(groupBox_5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        recvListWidget = new QListWidget(groupBox_5);
        recvListWidget->setObjectName(QString::fromUtf8("recvListWidget"));

        verticalLayout_2->addWidget(recvListWidget);


        verticalLayout_3->addWidget(groupBox_5);


        horizontalLayout_7->addWidget(widget_3);

        widget_4 = new QWidget(centralwindow);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        verticalLayout_4 = new QVBoxLayout(widget_4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        listWidget = new QListWidget(widget_4);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout_4->addWidget(listWidget);


        horizontalLayout_7->addWidget(widget_4);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 2);
        mainWindow->setCentralWidget(centralwindow);
        toolBar = new QToolBar(mainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        mainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        retranslateUi(mainWindow);

        QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainWindow)
    {
        mainWindow->setWindowTitle(QCoreApplication::translate("mainWindow", "mainWindow", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("mainWindow", "\350\277\236\346\216\245\344\277\241\346\201\257", nullptr));
        label_2->setText(QCoreApplication::translate("mainWindow", "ip", nullptr));
        ipLineEdit->setText(QCoreApplication::translate("mainWindow", "127.0.0.1", nullptr));
        label->setText(QCoreApplication::translate("mainWindow", "port", nullptr));
        portLineEdit->setText(QCoreApplication::translate("mainWindow", "10240", nullptr));
        connBtn->setText(QCoreApplication::translate("mainWindow", "connect", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("mainWindow", "\345\217\221\351\200\201\345\214\272", nullptr));
        sendTextEdit->setHtml(QCoreApplication::translate("mainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">cmd:noop</p></body></html>", nullptr));
        sendBtn->setText(QCoreApplication::translate("mainWindow", "send", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("mainWindow", "\346\216\245\346\224\266\345\214\272", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("mainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
