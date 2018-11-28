#include <cmath> // sqrt
#include <algorithm> // min, max
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
    return Linear_Search(arr, std::max(blockIndex - step, 0), std::min(blockIndex, arrSize), val);
}
