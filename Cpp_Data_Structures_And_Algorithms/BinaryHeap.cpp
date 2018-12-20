#include "BinaryHeap.h"

BinaryHeap::BinaryHeap() {
	vect.clear();

	// Root will be index 1,
	// set index 0 to be 'dummy'
	vect.push_back(-1);

	heapSize = 0;
}

bool BinaryHeap::IsEmpty() {
	return heapSize == 0;
}

void BinaryHeap::ShiftUp(int index) {
	// Do nothing in root
	if (index == 1)
		return;

	if (vect[index] > vect[p(index)]) {
		std::swap(vect[index], vect[p(index)]);

		// Recurse until root
		ShiftUp(p(index));
	}
}

void BinaryHeap::Insert(int key) {
	// Add a new element in vector
	if (heapSize + 1 >= (int)vect.size())
		vect.push_back(0);

	// Store the key in the vector last position
	vect[++heapSize] = key;

	ShiftUp(heapSize);
}

void BinaryHeap::ShiftDown(int i) {
	// Check index
	if (i > heapSize)
		return;

	// Initialize swapId
	int swapId = i;

	// Compare with left child, if exists
	if (l(i) <= heapSize && vect[swapId] < vect[l(i)])
		swapId = l(i);

	// Compare with right child, if exists
	if (r(i) <= heapSize && vect[swapId] < vect[r(i)])
		swapId = r(i);

	// Swap with the larger of the two children
	if (swapId != i) {
		// Swap downwards with the larger
		// of the two children
		std::swap(vect[i], vect[swapId]);

		// Recurse downward
		ShiftDown(swapId);
	}
}

int BinaryHeap::ExtractMax() {
	// Maximum value is in root
	const int maxVal = vect[1];

	// Swap with the last existing leaf
	std::swap(vect[1], vect[heapSize--]);

	// Fix heap property downwards
	ShiftDown(1);

	return maxVal;
}

int BinaryHeap::GetMax() {
	// Return root
	return vect[1];
}
