//
// Created by inrcl on 3/9/21.
//

#ifndef NETDISKT_ORDERCLI_MAINWINDOW_HPP
#define NETDISKT_ORDERCLI_MAINWINDOW_HPP

#include "m_msgqueue.hpp"
#include <mutex>
#include <QMainWindow>
#include <QTimer>

extern std::mutex uiw_mutex;
extern  m_msgqueue UIW_MsgQueue;
extern std::mutex iow_mutex;
extern m_msgqueue IOW_MsgQueue;

QT_BEGIN_NAMESPACE
namespace Ui { class mainWindow; }
QT_END_NAMESPACE

class mainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit mainWindow(QWidget * parent = nullptr);
    ~mainWindow() override;
    
public:
    int setInitParam(int argc, char * argv);
    
private:
    //void sctpstr_cli(void *fp, int fp_size, int sock_fd, struct sockaddr *to, socklen_t tolen); //tool function
    void signal();
    void componentInit(bool= false);
    void thWorkThread();
  //  int m_sctp_sendmsg(int s, const char *data, size_t len, struct sockaddr *to = nullptr,
    //        socklen_t tolen = 0, uint32_t ppid = 0, uint32_t flags = 0,
      //      uint16_t stream_no = 0, uint32_t timetolive = 0, uint32_t context = 0);
    
private:
//    struct sockaddr_in servaddr;
//    int sock_fd = -1;
    QAction *action01;
    QTimer *timer;

private:
    Ui::mainWindow * ui;
};

#endif //NETDISKT_ORDERCLI_MAINWINDOW_HPP
