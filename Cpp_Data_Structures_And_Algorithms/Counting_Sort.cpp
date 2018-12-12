void Counting_Sort(int arr[], const int &arrSize) {
	// Assuming all element values
	// are between 0 to 99 inclusive
	const int range = 100;

	// Create key/counting array.
	// Using new to allocate memory because in
	// practice won't know range in advance.
	int* countsArray = new int[range];

	// Generate the counts for the input array elements
	for (int i = 0; i < arrSize; ++i) {
		++countsArray[arr[i]];
	}

	int write_index = 0;

	// Write the elements back to original array
	for (int i = 0; i < range; ++i) {
		while (countsArray[i] > 0) {
			arr[write_index] = i;

			++write_index;
			--countsArray[i];
		}
	}

	delete[] countsArray;
}
