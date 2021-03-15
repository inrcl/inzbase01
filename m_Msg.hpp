//
// Created by inrcl on 3/14/21.
//

#ifndef NETDISKT_ORDERCLI_M_MSG_HPP
#define NETDISKT_ORDERCLI_M_MSG_HPP

#include <string>

class m_Msg {
public:
    m_Msg(int flags, const char * msg_str) : msgStr(msg_str), msg_flags(flags) { }
    m_Msg(int flags, const std::string msg_str) : msgStr(msg_str), msg_flags(flags) { }
    m_Msg& operator=(m_Msg& rhs) { this->msg_flags = rhs.msg_flags; this->msgStr = rhs.msgStr; return *this;}
    int msg_flags;
    std::string msgStr;
    
};

#endif //NETDISKT_ORDERCLI_M_MSG_HPP
