void Counting_Sort(int arr[], const int &arrSize) {
	// Assuming all element values
	// are between 0 to 99 inclusive
	const int range = 100;

	// Create key/counting array.
	// Using new to allocate memory because in
	// practice won't know range in advance.
	int* countsArray = new int[range];

	// Generate the counts for the input arr elements
	for (int i = 0; i < arrSize; ++i) {
		++countsArray[arr[i]];
	}

	int index = 0;

	for (int i = 0; i < range; ++i) {
		while (countsArray[i] > 0) {
			arr[index] = i;

			++index;
			--countsArray[i];
		}
	}

	delete[] countsArray;
}
