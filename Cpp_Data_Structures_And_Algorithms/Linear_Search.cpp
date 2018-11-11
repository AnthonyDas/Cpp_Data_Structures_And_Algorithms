int Linear_Search(int arr[], int startIndex, int endIndex, int val) {
	// Iterate through the start index to the end index and
	// return the searched value's index
	for (int i = startIndex; i < endIndex; ++i) {
		if (arr[i] == val) {
			return i;
		}
	}

	// return -1 if no val is found
	return -1;
}
