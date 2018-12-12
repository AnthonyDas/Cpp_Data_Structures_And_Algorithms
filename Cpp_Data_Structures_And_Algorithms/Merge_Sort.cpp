void Merge(int arr[], const int &start, const int &mid, const int &end) {
	// Total elements to sort, start to end inclusive
	const int totalElements = end - start + 1;

	// Temporary array to store (sorted) merged array
	int * tempArray = new int[totalElements];

	// Left subarray index arr[start, ..., mid]
	int leftIndex = start;

	// Right subarray index arr[(mid + 1), ..., end]
	int rightIndex = mid + 1;

	// Index in (sorted) merged array
	int mergedIndex = 0;

	// Merge the two subarrays
	while (leftIndex <= mid && rightIndex <= end) {
		if (arr[leftIndex] <= arr[rightIndex]) {
			tempArray[mergedIndex] = arr[leftIndex];
			++leftIndex;
		}
		else {
			tempArray[mergedIndex] = arr[rightIndex];
			++rightIndex;
		}

		++mergedIndex;
	}

	// Move any remaining left subarray elements to merged array
	while (leftIndex <= mid) {
		tempArray[mergedIndex] = arr[leftIndex];
		++leftIndex;
		++mergedIndex;
	}

	// Move any remaining right subarray elements to merged array
	while (rightIndex <= end) {
		tempArray[mergedIndex] = arr[rightIndex];
		++rightIndex;
		++mergedIndex;
	}

	// Copy the elements back in to the original array
	for (int i = 0; i < totalElements; ++i) {
		arr[start + i] = tempArray[i];
	}

	delete[] tempArray;
}

void MergeSort(int arr[], const int &start, const int &end) {
	// Only makes sense if sorting more than 1 element
	if (start < end) {

		const int mid = (start + end) / 2;

		// Sort left subarray arr[start, ..., mid]
		MergeSort(arr, start, mid);

		// Sort right subarray arr[(mid + 1), ..., end]
		MergeSort(arr, (mid + 1), end);

		Merge(arr, start, mid, end);
	}
}
