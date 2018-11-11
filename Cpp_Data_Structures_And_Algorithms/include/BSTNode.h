#ifndef BSTNODE_H
#define BSTNODE_H

class BSTNode {
public:

    int Key;
    BSTNode * Left;
    BSTNode * Right;
    BSTNode * Parent;

	int Height; // Needed for AVL Tree
};

#endif // BSTNODE_H
