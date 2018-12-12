#include <utility>

void SelectionSort(int arr[], const int &arrSize) {
	// Iterate until the second to last element
	for (int i = 0; i < (arrSize - 1); ++i) {
		// Index of the minimum value during each iteration.
		// Assume first unsorted element has the minimum value.
		int minIndex = i;

		// Iterate through the unsorted elements only
		for (int j = (i + 1); j < arrSize; ++j) {
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}

		std::swap(arr[i], arr[minIndex]);
	}
}
