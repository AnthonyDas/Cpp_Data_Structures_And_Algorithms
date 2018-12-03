#include <utility>

int Partition(int arr[], const int &start, const int &end) {
	// Set the first element as pivot
	const int pivotValue = arr[start];

	// mid is index of last left subarray element
	int mid = start;

	for (int i = (start + 1); i <= end; ++i) {
		if (arr[i] < pivotValue) {
			// Current item is in left subarray - shift mid index
			++mid;

			// arr[mid] is currently member of right subarray, swap
			// it with current element which is member of left subarray
			std::swap(arr[i], arr[mid]);
		}
	}

	// By now, arr[mid] is member of left subarray.
	// Swap it with pivot so the pivot will be in the correct
	// position in between left subarray and right subarray.
	std::swap(arr[start], arr[mid]);

	// Return index of pivot needed by next quick sort
	return mid;
}

void QuickSort(int arr[], const int &start, const int &end) {
	// Only makes sense to sort >1 element
	if (start < end) {

		// PivotIndex is index of element already in correct position
		const int pivotIndex = Partition(arr, start, end);

		// Sort left subarray arr[start, ..., (pivotIndex - 1)]
		QuickSort(arr, start, (pivotIndex - 1));

		// Sort right subarray arr[(pivotIndex + 1), ..., end]
		QuickSort(arr, (pivotIndex + 1), end);
	}
}
