#include "ioLogicModule.hpp"
#include <thread>
#include <QApplication>
#include "mainwindow.hpp"

#include "unp.h"
#include "sctpAdd/sctpAdd.hpp"
//#include <netinet/sctp.h>
std::mutex uiw_mutex;
std::mutex iow_mutex;
m_msgqueue UIW_MsgQueue;
m_msgqueue IOW_MsgQueue;

void thUI(int argc, char * argv[])
{
    QApplication a(argc, argv);
    
    mainWindow w;
    w.resize(800, 600);
    w.show();
    QApplication::exec();
}

void thIO()
{
   new ioLogicModule();
}

int main(int argc, char * argv[]) {
    std::thread *tui = new std::thread([=](){ thUI(argc, argv); });
    std::thread *tio = new std::thread([=](){ thIO(); });
    //std::thread chlidTh01 = std::thread([=](){ thread_make(0);});
    while (true) sleep(10);
    return 0;
}

//void sctpstr_cli(FILE *fp, int sock_fd, struct sockaddr *to, socklen_t tolen)
//{
//    struct  sockaddr_in peeraddr;
//    struct sctp_sndrcvinfo sri;
//    char sendline[MAXLINE], recvline[MAXLINE];
//    socklen_t len;
//    int out_sz, rd_sz;
//    int msg_flags;
//
//    bzero(&sri, sizeof(sri));
//    while (fgets(sendline, MAXLINE, fp) != NULL){
//        if (sendline[0] != '['){
//            printf("Error, line must be the form '[stremnum]text'\t");
//            continue;
//        }
//        sri.sinfo_stream = strtol(&sendline[1], NULL, 0);
//        out_sz = strlen(sendline);
//        Sctp_sendmsg(sock_fd, sendline, out_sz,
//                to, tolen,
//                0, 0, sri.sinfo_stream, 0,0);
//        len = sizeof(peeraddr);
//        rd_sz = Sctp_recvmsg(sock_fd, recvline, sizeof(recvline), (SA *)&peeraddr, &len, &sri, &msg_flags);
//        printf("Form str :%d seq:%d (assoc:0x%x):",
//                sri.sinfo_stream, sri.sinfo_ssn, (u_int)sri.sinfo_assoc_id);
//        printf("%.*s", rd_sz, recvline);
//
//    }
//}
//
//int stcpTestFunction(int argc, char * argv[])
//{
//    int sock_fd;
//    char readbuf[BUFFSIZE];
//    struct sockaddr_in servaddr;
////    struct sctp_sndrcvinfo sri;
//    struct sctp_event_subscribe events;
//    int echo_to_all = 0;
////    socklen_t len;
////    size_t rd_sz;
//
////    if (argc == 2)
////        stream_increment = atoi(argv[1]);
//    sock_fd = socket(AF_INET, SOCK_SEQPACKET, IPPROTO_SCTP);
//    bzero(&servaddr, sizeof(servaddr));
//    servaddr.sin_family = AF_INET;
//    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
//    servaddr.sin_port = htons(SERV_PORT);
//    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr);
//
////    bind(sock_fd, (SA *) &servaddr, sizeof(servaddr));
//
//    bzero(&events, sizeof(events));
//    events.sctp_data_io_event = 1;
//    setsockopt(sock_fd,IPPROTO_SCTP, SCTP_EVENTS, &events, sizeof(events));
//
////    listen(sock_fd, LISTENQ);
//    if (echo_to_all == 0)
//        sctpstr_cli(stdin, sock_fd, (SA *)&servaddr, sizeof(servaddr));
////    else
////        sctpstr_cli()
//    close(sock_fd);
//    return 0;
//
//}



