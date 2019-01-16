#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <vector>

class BinaryHeap {

    std::vector<int> vect;
    int heapSize;

public:

    BinaryHeap();

    bool IsEmpty();
    void Insert(const int&);
    int ExtractMax();
    int GetMax();

private:

    // three helper navigation function
    int p(int i) { return i>>1; } // Parent i/2
    int l(int i) { return i<<1; } // Left-child i*2
    int r(int i) { return (i<<1) + 1; } // Right-child (i*2) + 1

    void ShiftUp(int index);
    void ShiftDown(int i);
};

#endif // BINARYHEAP_H
