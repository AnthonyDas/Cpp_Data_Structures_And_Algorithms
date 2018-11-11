#include "Queue.h"

void RadixSort(int arr[], int arrSize) {
	// Create ten buckets for each digits (0 - 9)
	Queue<int> * buckets = new Queue<int>[10];

	// Find the largest element
	int largestElement = arr[0];
	for (int i = 0; i < arrSize; ++i) {
		if (largestElement < arr[i])
			largestElement = arr[i];
	}

	// Iterate through every digit
	// using exponetial (10^exp) to find the digit
	for (int exp = 1; largestElement / exp > 0; exp *= 10) {
		// Iterate the array's elements
		for (int i = 0; i < arrSize; ++i) {
			// Move element into respective bucket
			buckets[(arr[i] / exp) % 10].Enqueue(arr[i]);
		}

		// Reconstruct the array starting from
		// the smallest digit in the buckets
		// Reset the array counter before reconstructing
		int arrCounter = 0;
		for (int i = 0; i < 10; ++i) {
			// Get all elements from the buckets
			while (!buckets[i].IsEmpty()) {
				// Get the front element
				// then restore element to array
				arr[arrCounter++] = buckets[i].Front();

				// Remove the front element
				buckets[i].Dequeue();
			}
		}
	}
}
