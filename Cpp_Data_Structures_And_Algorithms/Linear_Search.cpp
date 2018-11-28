int Linear_Search(int arr[], const int &startIndex, const int &endIndex, const int &val) {
	for (int i = startIndex; i < endIndex; ++i) {
		if (arr[i] == val) {
			return i;
		}
	}

	// Not found
	return -1;
}
