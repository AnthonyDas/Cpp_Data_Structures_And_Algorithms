void Merge(int arr[], int startIndex, int middleIndex, int endIndex) {
	// Number of elements that will be sorted
	// from startIndex to endIndex inclusive
	int totalElements = endIndex - startIndex + 1;

	// Temporary array to store merged array
	int * tempArray = new int[totalElements];

	// Index of left subarray arr[startIndex, ..., middleIndex]
	int leftIndex = startIndex;

	// Index of right subarray arr[middleIndex + 1, ..., endIndex]
	int rightIndex = middleIndex + 1;

	// Index of merged array
	int mergedIndex = 0;

	// Merge the two subarrays
	while (leftIndex <= middleIndex && rightIndex <= endIndex) {
		if (arr[leftIndex] <= arr[rightIndex]) {
			tempArray[mergedIndex] = arr[leftIndex];
			++leftIndex;
		}
		else {
			tempArray[mergedIndex] = arr[rightIndex];
			++rightIndex;
		}

		// Go to next merged array index
		++mergedIndex;
	}

	// If there're any remaining element in left subarray
	// that is not stored to merged array yet
	while (leftIndex <= middleIndex) {
		tempArray[mergedIndex] = arr[leftIndex];

		// Go to next left subarray index
		++leftIndex;

		// Go to next merged array index
		++mergedIndex;
	}

	// If there're any remaining element in right subarray
	// that is not stored to merged array yet
	while (rightIndex <= endIndex) {
		tempArray[mergedIndex] = arr[rightIndex];

		// Go to next right subarray index
		++rightIndex;

		// Go to next merged array index
		++mergedIndex;
	}

	// Now, the merged array has been sorted
	// Copy the elements to the original array
	for (int i = 0; i < totalElements; ++i) {
		arr[startIndex + i] = tempArray[i];
	}

	// Remove the temporary array tempArray
	delete[] tempArray;
}

void MergeSort(int arr[], int startIndex, int endIndex) {
	// Only perform sort process
	// if the end index is higher than start index
	if (startIndex < endIndex) {
		// Find middle index
		int middleIndex = (startIndex + endIndex) / 2;

		// Sort left subarray
		// arr[startIndex ... middleIndex]
		MergeSort(arr, startIndex, middleIndex);

		// Sort right subarray
		// arr[middleIndex + 1 ... endIndex]
		MergeSort(arr, middleIndex + 1, endIndex);

		// Merge the left and the right subarray
		Merge(arr, startIndex, middleIndex, endIndex);
	}
}
