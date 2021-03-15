//
// Created by inrcl on 3/9/21.
//

// You may need to build the project (run Qt uic code generator) to get "ui_mainWindow.h" resolved

#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "QPushButton"
#include "QToolBar"

#include <sys/epoll.h>
#include "errno.h"
#include "m_fileprogressbar.hpp"


#define MAXEVENTS 64


mainWindow::mainWindow(QWidget * parent)
        :
        QMainWindow(parent), ui(new Ui::mainWindow) {
    ui->setupUi(this);
    
    timer = new QTimer(this);
    timer->start(300);
//    QPushButton *button = new QPushButton("Hello Client !!!", this);
//    button->resize(200, 100);
   
    ui->toolBar->setGeometry(0,40,width(),40);
    action01 = new QAction("aaa",this);
    action01->setCheckable(true);
    ui->toolBar->addAction(action01);

    signal();
    componentInit();
    
    /* new transfer list */
    m_fileProgressBar * mfpb = new m_fileProgressBar();
    
    QListWidgetItem *atiem = new QListWidgetItem();
    ui->listWidget->addItem(atiem);
    
    atiem->setSizeHint(mfpb->sizeHint());
    
    ui->listWidget->setItemWidget(atiem, mfpb);
    
}

mainWindow::~mainWindow() {
    delete ui;
    exit(0);
}

void push2msgqueue(const m_Msg &msg)
{
    uiw_mutex.lock();
    UIW_MsgQueue.push(msg);
    uiw_mutex.unlock();
}

 std::string popformmsgqueue()
{
    m_Msg strMsg = m_Msg(0, "");
    iow_mutex.lock();
    if (IOW_MsgQueue.empty() == false){
        strMsg = IOW_MsgQueue.front();
        IOW_MsgQueue.pop();
    }
    iow_mutex.unlock();
    return strMsg.msgStr;
}

void mainWindow::signal()
{
    connect(ui->connBtn, &QPushButton::clicked, [this](){
        std::string ipStr ( ui->ipLineEdit->text().toLocal8Bit().data());
        std::string portStr(ui->portLineEdit->text().toLocal8Bit().data());
        auto btnText = ui->connBtn->text();
        if (ipStr.empty() == false && portStr.empty() == false) //ip & port not empty
        {
            
            bool ok;
            
            if (btnText == "connect"){
                ui->connBtn->setText("Disconnext");
                ui->recvListWidget->addItem(QStringLiteral("start connect..."));
               push2msgqueue({1,ipStr + ":" + portStr});
                componentInit(true);
            }
            else
            {
                ui->connBtn->setText("connect");
                push2msgqueue({-1,"disconn 1 sockfd"});
                componentInit(false);
            }
            
        }
    });
    
    connect(ui->sendBtn, &QPushButton::clicked, [this](){
        std::string sendText(ui->sendTextEdit->toPlainText().toLocal8Bit().data());
        push2msgqueue({11, sendText});
       // sctpstr_cli(sendText.toLocal8Bit().data(), sendText.size(), sock_fd, (SA *)&servaddr, sizeof(servaddr));
    });
    
    QObject::connect(action01, &QAction::changed, [this](){
        push2msgqueue({-1,"disconn 1 sockfd"});
        componentInit(false);
        ui->connBtn->setText("connect");
    });
    connect(timer, &QTimer::timeout, [=](){
        std::string recvStr = popformmsgqueue();
        if(recvStr.empty() == false)
            ui->recvListWidget->addItem(recvStr.c_str());
    });
}

void mainWindow::componentInit(bool stutas)
{
    ui->sendTextEdit->setEnabled(stutas);
    ui->sendBtn->setEnabled(stutas);
}

