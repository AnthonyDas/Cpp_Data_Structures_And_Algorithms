#include "Swap.h"

void SelectionSort(int arr[], const int &arrSize) {
	// Index of the minimum value during each iteration
	int minIndex;

	// Iterate until the second to last element
	for (int i = 0; i < (arrSize - 1); ++i) {
		// Assume first unsorted element
		// has the minimum value
		minIndex = i;

		// Iterate through the unsorted elements only
		for (int j = (i + 1); j < arrSize; ++j) {
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}

		swap(arr[i], arr[minIndex]);
	}
}
