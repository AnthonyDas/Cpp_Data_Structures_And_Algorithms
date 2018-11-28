int Linear_Search(int arr[], const int &start, const int &end, const int &val) {
	// Only process if start index <= end index
	for (int i = start; i <= end; ++i) {
		if (arr[i] == val) {
			return i;
		}
	}

	// Not found
	return -1;
}
