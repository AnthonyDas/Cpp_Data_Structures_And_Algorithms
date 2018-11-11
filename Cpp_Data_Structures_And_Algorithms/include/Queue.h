#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

template <typename T>
class Queue {

    int m_count;
    Node<T> * m_front;
    Node<T> * m_back;

public:

    Queue() : m_count(0), m_front(nullptr), m_back(nullptr) {};
	~Queue();
    bool IsEmpty();
    T Front();
    void Enqueue(T val);
    void Dequeue();
};

#endif // QUEUE_H
