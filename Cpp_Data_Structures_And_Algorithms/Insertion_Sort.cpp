void InsertionSort(int arr[], const int &arrSize) {
	// Start at second element
	for (int i = 1; i < arrSize; ++i) {
		// Set the current element as reference value
		int refValue = arr[i];

		// Index where refValue should be placed
		int j;

		// Iterate through the sorted elements to insert
		// the reference value in correct position
		for (j = (i - 1); j >= 0; --j) {
			// If value at index j is greater than
			// the reference value then shift it to
			// the right. Otherwise, put the reference
			// value at index (j + 1).
			if (arr[j] > refValue) {
				arr[j + 1] = arr[j];
			}
			else {
				break;
			}
		}

		// Put reference value into sorted position
		arr[j + 1] = refValue;
	}
}
