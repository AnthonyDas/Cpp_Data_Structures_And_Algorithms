#ifndef AVL_H
#define AVL_H

#include "BST.h"

class AVL : public BST {
public:

	AVL() : BST() {};
	~AVL();
    
private:

	int GetHeight(BSTNode * node);
	BSTNode * RotateLeft(BSTNode * node);
	BSTNode * RotateRight(BSTNode * node);

	BSTNode * Insert(BSTNode * node, int key) override;
	BSTNode * Remove(BSTNode * node, int key) override;

};

#endif // AVL_H
