//
// Created by inrcl on 3/13/21.
//

#ifndef NETDISKT_ORDERCLI_M_MSGQUEUE_HPP
#define NETDISKT_ORDERCLI_M_MSGQUEUE_HPP
#include <algorithm>
#include <queue>
#include "m_Msg.hpp"



class m_msgqueue{
public:
    m_msgqueue() { m_que = new std::queue<m_Msg>(); }
    ~m_msgqueue();
    
    bool empty() const;
    size_t size() const;
    
    m_Msg& front();
    const m_Msg& front() const; //返回队列中第一个元素,即最后插入到队列中的那个元素
    
    m_Msg& back();
    const m_Msg& back() const; //返回队列中最后一个元素，即最先入队的那个元素
    
    void push (const m_Msg& val); // 插入一个新元素在队尾
    
    void pop(); //移除队首元素
    
    
private:
    //m_Msg m_msg;
    std::queue<m_Msg> *m_que;
    
};




#endif //NETDISKT_ORDERCLI_M_MSGQUEUE_HPP
