#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
public:

    T Value;
    Node<T> * Next;

    Node(T value) : Value(value), Next(nullptr) {};
};


#endif // NODE_H
