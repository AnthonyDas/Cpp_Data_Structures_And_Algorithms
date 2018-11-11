void Counting_Sort(int arr[], int arrSize) {
	// Create key/counting array
	// with assumption that all element value
	// are from 0 to 9
	int counterSize = 10;
	int* counterArray = new int[counterSize];

	// Increase the respective counter by 1
	for (int i = 0; i < arrSize; ++i) {
		++counterArray[arr[i]];
	}

	// Counter for iterating the arrCounter array
	int arrCounter = 0;

	for (int i = 0; i < counterSize; ++i) {
		while (counterArray[i] > 0) {
			// Restore element to list
			arr[arrCounter++] = i;

			// Decrease counter by 1
			--counterArray[i];
		}
	}

	delete[] counterArray;
}
