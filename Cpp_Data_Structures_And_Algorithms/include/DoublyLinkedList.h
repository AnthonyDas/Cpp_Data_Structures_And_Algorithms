#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "DoublyNode.h"

template <typename T>
class DoublyLinkedList {

	int m_count;

public:

	// The first node in the list
	// or null if empty
	DoublyNode<T> * Head;

	// The last node in the list
	// or null if empty
	DoublyNode<T> * Tail;

	// Constructor
	DoublyLinkedList() : m_count(0), Head(nullptr), Tail(nullptr) {};

	~DoublyLinkedList();

	// Get() operation
	DoublyNode<T> * Get(int index);

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
	void PrintListBackward();
};

#endif // DOUBLYLINKEDLIST_H
