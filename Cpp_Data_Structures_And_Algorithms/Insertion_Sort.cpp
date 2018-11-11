void InsertionSort(int arr[], int arrSize) {
	// Iterate to all array's element
	for (int i = 0; i < arrSize; ++i) {
		// Set the current element
		// as reference value
		int refValue = arr[i];

		// variable to shift the element
		// to right position
		int j;

		// Iterate through the sorted element
		// to insert the reference value
		// in right position
		for (j = (i - 1); j >= 0; --j) {
			// if the value of the current index
			// is greater than the reference value then
			// move the current value to right side
			// otherwise, put the reference value
			// in the current index
			if (arr[j] > refValue)
				arr[j + 1] = arr[j];
			else
				break;
		}

		// here's the line to put the reference value
		// in the current index (the right position)
		arr[j + 1] = refValue;
	}
}
