#include <algorithm> // max
#include <queue>

void RadixSort(int arr[], const int &arrSize) {
	// Create ten buckets for digits 0 - 9
	constexpr int ten = 10;
	std::queue<int> buckets[ten];

	// Find the largest element
	int largest = arr[0];
	for (int i = 0; i < arrSize; ++i) {
		largest = std::max(largest, arr[i]);
	}

	// Iterate through every digit using exponetial
	// (10^exp) to find the next digit
	for (int exp = 1; (largest / exp) > 0; exp *= 10) {
		// Iterate through array moving element into respective bucket
		for (int i = 0; i < arrSize; ++i) {
			buckets[(arr[i] / exp) % 10].push(arr[i]); // enqueue
		}

		// Reconstruct the array starting from
		// the smallest digit bucket
		int write_index = 0;
		for (int i = 0; i < ten; ++i) {
			while (!buckets[i].empty()) {
				arr[write_index] = buckets[i].front();

				buckets[i].pop(); // dequeue

				++write_index;
			}
		}
	}
}
