#include <algorithm> // min
#include "Binary_Search.h"

int Exponential_Search(int arr[], const int &arrSize, const int &val) {
    // Impossible to search over empty arr
    if (arrSize <= 0) {
        return -1;
    }

    // Start at 1. Will multiply by 2, so cannot start from zero
    int blockIndex = 1;

    // Increase blockIndex exponentially if:
	// - lower than array size, and
    // - element at blockIndex is smaller than target value
    while (blockIndex < arrSize && arr[blockIndex] < val) {
        blockIndex *= 2;
    }

    // BlockIndex will be pass the target, so perfom Binary Search
	// on the sub array starting at (blockIndex / 2)
    // arr[(blockIndex / 2), ..., (blockIndex or arrSize)]
    return Binary_Search(arr, (blockIndex / 2), std::min(blockIndex, arrSize), val);
}
