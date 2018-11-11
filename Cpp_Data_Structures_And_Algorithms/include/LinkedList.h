#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template <typename T>
class LinkedList {

    int m_count;

public:

    // The first node in the list
    // or null if empty
    Node<T> * Head;

    // The last node in the list or null if empty
	// redundant in single linked list but needed when we come onto double linked lists
    Node<T> * Tail;

    // Constructor
    LinkedList() : m_count(0), Head(nullptr), Tail(nullptr) {};

	~LinkedList();

    // Get() operation
    Node<T> * Get(int index);

    // Insert() operation
    void InsertHead(T val);
    void InsertTail(T val);
    void Insert(int index, T val);

    // Search() operation
    int Search(T val);

    // Remove() operation
    void RemoveHead();
    void RemoveTail();
    void Remove(int index);

    // Additional operation
    int Count();
    void PrintList();
};

#endif // LINKEDLIST_H
