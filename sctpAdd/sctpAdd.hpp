//
// Created by inrcl on 3/8/21.
//

#ifndef QTPROJECTTEST02_SCTPADD_HPP
#define QTPROJECTTEST02_SCTPADD_HPP
#include "unp.h"
#include "error.hpp"

extern "C"
sctp_assoc_t
sctp_address_to_associd(int sock_fd, struct sockaddr *sa, socklen_t salen);  //sctp_addr_to_associd.c

extern "C"
int
sctp_bind_arg_list(int sock_fd, char **argv, int argc); //sctp_bindargs.c

extern "C"
int
sctp_get_no_strms(int sock_fd,struct sockaddr *to, socklen_t tolen); //sctp_getnostrm.c

extern "C"
int
Sctp_recvmsg(int s, void *msg, size_t len,
        struct sockaddr *from, socklen_t *fromlen,
        struct sctp_sndrcvinfo *sinfo,
        int *msg_flags);

extern "C"
int
Sctp_sendmsg (int s, void *data, size_t len, struct sockaddr *to,
        socklen_t tolen, uint32_t ppid, uint32_t flags,
        uint16_t stream_no, uint32_t timetolive, uint32_t context);

extern "C"
int
Sctp_bindx(int sock_fd,struct sockaddr_storage *at,int num,int op); //sctp_wrapper.c

//extern "C"
//int connect (int __fd, __CONST_SOCKADDR_ARG __addr, socklen_t __len);

int m_Connect (int fd, __CONST_SOCKADDR_ARG addr, socklen_t len);


#endif //QTPROJECTTEST02_SCTPADD_HPP
