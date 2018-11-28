#include <cmath> // sqrt
#include <algorithm> // min
#include "Linear_Search.h"

int Jump_Search(int arr[], const int &arrSize, const int &val) {
	// Impossible to search over empty arr
    if (arrSize <= 0) {
        return -1;
    }

    const int step = std::sqrt(arrSize);

    int blockIndex = 0;

	// Increase blockIndex by step if:
	// - lower than array size, and
	// - element at blockIndex is smaller than target value
    while (blockIndex < arrSize && arr[blockIndex] < val) {
        blockIndex += step;
    }

	// BlockIndex will be pass the target, so perfom Linear Search
	// on the sub array starting at (blockIndex - step)
    // arr[(blockIndex - step), ..., (blockIndex or arrSize)]
    return Linear_Search(arr, (blockIndex - step), std::min(blockIndex, arrSize), val);
}
