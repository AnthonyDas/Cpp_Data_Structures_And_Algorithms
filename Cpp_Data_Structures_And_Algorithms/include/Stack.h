#ifndef STACK_H
#define STACK_H

#include "Node.h"

template <typename T>
class Stack {

    int m_count;
    Node<T> * m_top;

public:

    Stack() : m_count(0), m_top(nullptr) {};
	~Stack();
    bool IsEmpty();
    T Top();
    void Push(T val);
    void Pop();
};

#endif // STACK_H
