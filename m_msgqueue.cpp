//
// Created by inrcl on 3/13/21.
//

#include "m_msgqueue.hpp"

m_msgqueue::~m_msgqueue()
{
    delete m_que;
}

bool m_msgqueue::empty() const
{
    return m_que->empty();
}
size_t m_msgqueue::size() const
{
    return m_que->size();
}

m_Msg& m_msgqueue::front()
{
    return m_que->front();
}
const m_Msg& m_msgqueue::front() const
{
    return m_que->front();
}

m_Msg& m_msgqueue::back()
{
    return m_que->back();
}
const m_Msg& m_msgqueue::back() const
{
    return m_que->back();
}

void m_msgqueue::push (const m_Msg& val)
{
    return m_que->push(val);
}

void m_msgqueue::pop()
{
    return m_que->pop();
}