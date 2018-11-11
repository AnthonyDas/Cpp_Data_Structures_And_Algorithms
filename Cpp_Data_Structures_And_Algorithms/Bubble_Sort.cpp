#include "Swap.h"

void Bubble_Sort(int arr[], int arrSize) {
	// Flag for swapping element
	bool isSwapped;

	// The value will be decreased
	// every time one element has been sorted
	int unsortedElements = arrSize;

	do {
		// If there's at least two element are swapped
		// it will be true
		isSwapped = false;

		// Iterate through the array's element
		for (int i = 0; i < unsortedElements - 1; ++i) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				isSwapped = true;
			}
		}

		// After iteration, the last element has been sorted
		// so it will be ignored in the next iteration
		--unsortedElements;
	}
	// Do comparison again if there's swapped element
	// otherwise, all array's elements have been sorted
	while (isSwapped); // do-while
}

