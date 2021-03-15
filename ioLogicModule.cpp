//
// Created by inrcl on 3/13/21.
//

#include <memory>
#include "ioLogicModule.hpp"
#include <sys/epoll.h>

//#include <netinet/sctp.h>

#define MAXEVENTS 64

int epoll_fd;
struct epoll_event ep_event;
std::shared_ptr<epoll_event[]> p_epoll_event(new epoll_event[MAXEVENTS]());

void push2msgqueue_io(const m_Msg &msg)
{
    iow_mutex.lock();
    IOW_MsgQueue.push(msg);
    iow_mutex.unlock();
}

m_Msg popformmsgqueue_io()
{
    m_Msg strMsg = m_Msg(0, "");
    uiw_mutex.lock();
    if (UIW_MsgQueue.empty() == false){
        strMsg = UIW_MsgQueue.front();
        UIW_MsgQueue.pop();
    }
    uiw_mutex.unlock();
    return strMsg;
}

ioLogicModule::ioLogicModule(){
    while (true)
    {
        m_Msg msgStr = popformmsgqueue_io();
        auto recvStr_ui = msgStr.msgStr;
        if (recvStr_ui.empty() == false){
            if (msgStr.msg_flags == 1){      // Init connect sockfd
                int pos = recvStr_ui.find(':');
                auto ipStr = msgStr.msgStr.substr(0, pos);
                auto portStr = msgStr.msgStr.substr(pos +1);
                std::cerr << ipStr << portStr;
                push2msgqueue_io({1,"recvice param success"});
                if (setInitParam(std::atoi(portStr.c_str()), ipStr.c_str()) == 0){
                    push2msgqueue_io({1,"connect success"});
                }
                
            }
            else if (msgStr.msg_flags == -1){ //disconect init socket
                std::cerr << msgStr.msgStr;
                close(sock_fd);
                push2msgqueue_io({1,"disconnect success"});
            }
            else if (msgStr.msg_flags == 11) {
                sctpstr_cli(const_cast<char *>(recvStr_ui.c_str()), recvStr_ui.size(), sock_fd, (struct sockaddr *)&servaddr, sizeof(servaddr));
            }
            
        }else
            sleep(1);
    }
    
}

ioLogicModule::~ioLogicModule(){

}
int ioLogicModule::setInitParam(int port, const char * cpip)
{
//    int sock_fd;
    char readbuf[BUFFSIZE];
//    struct sockaddr_in servaddr;
//    struct sctp_sndrcvinfo sri;
    struct sctp_event_subscribe events;
    int echo_to_all = 0;
//    socklen_t len;
//    size_t rd_sz;

//    if (argc == 2)
//        stream_increment = atoi(argv[1]);
    epoll_fd = epoll_create1(0);
    if (epoll_fd < 0)
        printf("epoll callback error!");
    
    
    sock_fd = socket(AF_INET, SOCK_SEQPACKET, IPPROTO_SCTP);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);//SERV_PORT);
    inet_pton(AF_INET, cpip, &servaddr.sin_addr);

//    bind(sock_fd, (SA *) &servaddr, sizeof(servaddr));
    
    bzero(&events, sizeof(events));
    events.sctp_data_io_event = 1;
    setsockopt(sock_fd,IPPROTO_SCTP, SCTP_EVENTS, &events, sizeof(events));

//    listen(sock_fd, LISTENQ);
//    if (echo_to_all == 0)
//        sctpstr_cli(stdin, sock_fd, (SA *)&servaddr, sizeof(servaddr));
//    else
//        sctpstr_cli()
    int connStutas = ::connect(sock_fd,(SA *)&servaddr, sizeof(servaddr));
    if (connStutas == 0)
    {
        std::cout << "connect Success!\n";

    }
    else
    {
        std::cerr << "connect Error!";
        return -1;
    }
    
    ep_event.data.fd = sock_fd;
    ep_event.events = EPOLLIN | EPOLLRDHUP;  //read write
    //  ep_event.events = EPOLLIN | EPOLLRDHUP;  //read write
    
    int ret = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, sock_fd, &ep_event);
    if (ret == -1)
        printf("epoll_crl failt");
    
    return 0;
    
    
}

void ioLogicModule::sctpstr_cli(void *fp, int fp_size, int sock_fd, struct sockaddr *to, socklen_t tolen)
{
    struct  sockaddr_in peeraddr;
    struct sctp_sndrcvinfo sri;
    char *sendline, recvline[MAXLINE];
    socklen_t len;
    int out_sz, rd_sz;
    int msg_flags;
    char readbuf[BUFFSIZE];
    struct epoll_event *ep_events = p_epoll_event.get();
    
    bzero(&sri, sizeof(sri));
    
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
    
    std::string sndtext(reinterpret_cast<char *>(fp),fp_size);
    if (sndtext.find("cmd:") == 0){
        sndtext.append("\r\n");
        fp_size += 2;
    }
    sendline = const_cast<char *>(sndtext.c_str());
    bzero(&sri, sizeof(sri));
    int eventCnt;
    //input slotfun
    //    while (fgets(sendline, MAXLINE, fp) != NULL){

    sri.sinfo_stream = strtol("0", NULL, 0);
    out_sz = strlen(sendline);
    
    Sctp_sendmsg(sock_fd, sendline, fp_size,
            to, tolen,
            0, 0, sri.sinfo_stream, 0,0);
    if (sndtext.find("cmd:quit\r\n") == 0){
        return;
    }
    
    int recvMsgCnt = 0;
    while (true){
        eventCnt = epoll_wait(epoll_fd, ep_events, MAXEVENTS, -1);
        if ((eventCnt == 0) || (eventCnt == -1))
            break;
        for (int i = 0; i < eventCnt; ++i){
            if (ep_events[i].events & EPOLLERR || ep_events[i].events & EPOLLHUP){
                fprintf(stderr,"sock_fd file error or file disconnect\n");
                ::close(ep_events[i].data.fd);
                exit(-1);
            }
            if (ep_events[i].events & EPOLLIN) {
                len = sizeof(peeraddr);
                bzero(&peeraddr, len);
                bzero(readbuf, BUFFSIZE);
                
                while( (rd_sz = //Sctp_recvmsg(sock_fd, readbuf, sizeof(readbuf), (SA *)&peeraddr, &len, &sri, &msg_flags);
                                sctp_recvmsg(sock_fd,reinterpret_cast<void *>(readbuf),sizeof(readbuf),(SA *)&peeraddr, &len, NULL, &msg_flags)) ==-1){
                    int ret = read(sock_fd, readbuf, sizeof(readbuf));
                    perror("sctp_recvmsg ");
                    fprintf(stderr, "sctp_recvmsg param error\n");
                    return;
                }
                
                
                if (rd_sz == 11 && (strncmp(readbuf, "cmd:over\r\n", 10) == 0)) {
                    std::cout<< readbuf;
                    fprintf(stderr, "recviced %d message.", recvMsgCnt);
                    return;
                }else
                {
//                    ui->recvListWidget->addItem(QString::asprintf("Form str :%d seq:%d (assoc:0x%x): %.*s",
//                            sri.sinfo_stream, sri.sinfo_ssn, (u_int)sri.sinfo_assoc_id, rd_sz, recvline));
                    ++recvMsgCnt;
                    push2msgqueue_io({11, readbuf});
                   std::cout<< readbuf;
                }
                
                //        printf("Form str :%d seq:%d (assoc:0x%x):",
//                sri.sinfo_stream, sri.sinfo_ssn, (u_int)sri.sinfo_assoc_id);
//        printf("%.*s", rd_sz, recvline);
            }
//            else if (ep_events[i].events & EPOLLOUT) {
//                if (sndtext.empty() == false){
//                    Sctp_sendmsg(sock_fd, sendline, fp_size,
//                            to, tolen,
//                            0, 0, sri.sinfo_stream, 0,0);
//                    sndtext.resize(0);
//                } else{
//                    if (isRecvOver){
//                        return;
//                    }
//                    continue;
//                }
//            }
        
        }
        
        
    }
}

void ioLogicModule::thTransferFile(const char * file)
{
//    int sock_fd;
//    char readbuf[BUFFSIZE];
//    struct sockaddr_in servaddr;
//    struct sctp_sndrcvinfo sri;
//    struct sctp_event_subscribe events;
//    int echo_to_all = 0;
//    socklen_t len;
//    size_t rd_sz;
//
//
//    sock_fd = socket(AF_INET, SOCK_SEQPACKET, IPPROTO_SCTP);
//    bzero(&servaddr, sizeof(servaddr));
//    servaddr.sin_family = AF_INET;
//    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
//    servaddr.sin_port = htons(port);//SERV_PORT);
//    inet_pton(AF_INET, cpip, &servaddr.sin_addr);
//
//    bzero(&events, sizeof(events));
//    events.sctp_data_io_event = 1;
//    setsockopt(sock_fd,IPPROTO_SCTP, SCTP_EVENTS, &events, sizeof(events));
//
////    if (echo_to_all == 0)
////        sctpstr_cli(stdin, sock_fd, (SA *)&servaddr, sizeof(servaddr));
////    else
////        sctpstr_cli()
//    int connStutas = ::connect(sock_fd,(SA *)&servaddr, sizeof(servaddr));
//    if (connStutas == 0)
//    {
//        std::cout << "connect Success!\n";
//
//    }
//    else
//    {
//        std::cerr << "connect Error!";
//        return ;
//    }
//
//    ep_event.data.fd = sock_fd;
//    ep_event.events = EPOLLIN | EPOLLRDHUP;  //read write
//
//    int ret = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, sock_fd, &ep_event);
//    if (ret == -1)
//        printf("epoll_crl failt");
//
//    bzero(&sri, sizeof(sri));
//
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
//
//
    
    return ;
    
    
}
