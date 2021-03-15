//
// Created by inrcl on 3/13/21.
//

#ifndef NETDISKT_ORDERCLI_IOLOGICMODULE_HPP
#define NETDISKT_ORDERCLI_IOLOGICMODULE_HPP
#include <string>
#include <iostream>
#include <mutex>

#include "m_msgqueue.hpp"
#include "unp.h"
#include "sctpAdd/sctpAdd.hpp"

extern std::mutex uiw_mutex;
extern m_msgqueue UIW_MsgQueue;
extern std::mutex iow_mutex;
extern m_msgqueue IOW_MsgQueue;

class ioLogicModule {
public:
    ioLogicModule();
    ~ioLogicModule();
    
    int setInitParam(int argc, const char * argv); //Init NO.1 socket
    
    void sctpstr_cli(void *fp, int fp_size, int sock_fd, struct sockaddr *to, socklen_t tolen); //send function
    
    void thTransferFile(const char *);

private:
    struct sockaddr_in servaddr;
    int sock_fd = -1;
};

#endif //NETDISKT_ORDERCLI_IOLOGICMODULE_HPP
