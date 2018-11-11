#ifndef DOUBLYNODE_H
#define DOUBLYNODE_H

template <typename T>
class DoublyNode {
public:

	T Value;
	DoublyNode<T> * Previous;
	DoublyNode<T> * Next;

	DoublyNode(T value) : Value(value), Previous(nullptr), Next(nullptr) {};
};

#endif // DOUBLYNODE_H
