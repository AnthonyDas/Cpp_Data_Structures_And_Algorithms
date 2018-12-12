#include <utility>

void Bubble_Sort(int arr[], const int &arrSize) {
	// Flag to indicate whether any elements swapped during iteration
	bool isSwapped; 

	// Decreased every time one element has been sorted
	int unsortedElements = arrSize;

	do {
		isSwapped = false;

		// Iterate through the array's element
		// NB. -1 second to last element
		for (int i = 0; i < (unsortedElements - 1); ++i) { 
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				isSwapped = true;
			}
		}

		// Last element has been sorted so ignored it
		// during the next iteration
		--unsortedElements;
	}
	// Do comparison again if there's swapped element
	// otherwise, all array's elements have been sorted
	while (isSwapped); // do-while
}