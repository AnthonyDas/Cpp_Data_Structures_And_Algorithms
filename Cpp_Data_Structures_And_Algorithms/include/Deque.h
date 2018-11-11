#ifndef DEQUE_H
#define DEQUE_H

#include "DoublyNode.h"

template <typename T>
class Deque {

    int m_count;
    DoublyNode<T> * m_front;
    DoublyNode<T> * m_back;

public:

    Deque() : m_count(0), m_front(nullptr), m_back(nullptr) {};
	~Deque();
    bool IsEmpty();
    T Front();
    T Back();
    void EnqueueFront(T val);
    void EnqueueBack(T val);
    void DequeueFront();
    void DequeueBack();
};

#endif // DEQUE_H
