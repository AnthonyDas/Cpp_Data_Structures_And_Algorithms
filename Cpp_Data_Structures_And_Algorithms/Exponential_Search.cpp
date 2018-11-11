#include <algorithm> // min
#include "Binary_Search.h"

int Exponential_Search(int arr[], int arrSize, int val) {
    // It's impossible to search value
    // in array contains zero or less element
    if (arrSize <= 0) {
        return -1;
    }

    // Start comparing from index 1
    int blockIndex = 1;

    // Increase the blockIndex exponentially
    // if blockIndex is lower than array size
    // and the value of element in blockIndex
    // is still lower than searched value
    while (blockIndex < arrSize && arr[blockIndex] < val) {
        blockIndex *= 2;
    }

    // After find the blockIndex,
    // perfom Binary Search to the sub array
    // defined by the blockIndex
    // arr[blockIndex / 2 .... blockIndex or arrSize]
    return Binary_Search(arr, (blockIndex / 2), std::min(blockIndex, arrSize), val);
}
