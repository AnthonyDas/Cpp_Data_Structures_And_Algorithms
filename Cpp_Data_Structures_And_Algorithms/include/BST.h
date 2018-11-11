#ifndef BST_H
#define BST_H

#include "BSTNode.h"

class BST {
protected:

    BSTNode * root;

public:

	BST() : root(nullptr) {};
	virtual ~BST();

    void Insert(int key);
    void PrintTreeInOrder();
    bool Search(int key);
    int FindMin();
    int FindMax();
    int Successor(int key);
    int Predecessor(int key);
	void Remove(int key);

protected:

	virtual BSTNode * Insert(BSTNode * node, int key);
	void PrintTreeInOrder(BSTNode * node);
	BSTNode * Search(BSTNode * node, int key);
	int FindMin(BSTNode * node);
	int FindMax(BSTNode * node);
	int Successor(BSTNode * node);
	int Predecessor(BSTNode * node);
	virtual BSTNode * Remove(BSTNode * node, int key);
};

#endif // BST_H
