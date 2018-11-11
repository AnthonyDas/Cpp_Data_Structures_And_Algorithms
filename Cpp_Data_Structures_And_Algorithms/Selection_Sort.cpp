#include "Swap.h"

void SelectionSort(int arr[], int arrSize) {
	// variable to store the index of the minimum value
	// in each iteration
	int minIndex;

	// Iterate until the N-1 elements
	for (int i = 0; i < arrSize - 1; ++i) {
		// Set the first unsorted element
		// as the minimum value
		minIndex = i;

		// Iterate through the unsorted elements only
		for (int j = i + 1; j < arrSize; ++j) {
			// set the new minimum value
			// if the saved minimum value is higher
			// than the current index value
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}

		// Swap the the first unsorted element
		// with the minimum value
		swap(arr[i], arr[minIndex]);
	}
}
