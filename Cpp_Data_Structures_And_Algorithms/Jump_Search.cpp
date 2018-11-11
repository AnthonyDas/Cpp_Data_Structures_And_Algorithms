#include <cmath> // sqrt
#include <algorithm> // min
#include "Linear_Search.h"

int Jump_Search(int arr[], int arrSize, int val) {
    // It's impossible to search value
    // in array contains zero or less element
    if (arrSize <= 0) {
        return -1;
    }

    // Defining step used to jump the array
    int step = std::sqrt(arrSize);

    // Start comparing from index 0
    int blockIndex = 0;

    // Increase the blockIndex by the step
    // if blockIndex is lower than array size
    // and the value of element in blockIndex
    // is still lower than searched value
    while (blockIndex < arrSize && arr[blockIndex] < val) {
        blockIndex += step;
    }

    // After find the blockIndex,
    // perform Linear Search to the sub array
    // defined by the blockIndex
    // arr[blockIndex - step .... blockIndex or arrSize]
    return Linear_Search(arr, (blockIndex - step), std::min(blockIndex, arrSize), val);
}
