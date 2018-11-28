int Binary_Search(int arr[], const int &start, const int &end, const int &val) {
	// Only process if start index <= end index
	if (start <= end) {
		const int mid = start + (end - start) / 2;

		// Is middle value the target value?
		if (arr[mid] == val) {
			return mid;
		}
		// If the middle value is greater than target value,
		// perform Binary Search on the left sub array
		// arr[start, ..., (mid - 1)]
		else if (arr[mid] > val) {
			return Binary_Search(arr, start, (mid - 1), val);
		}
		// If the middle value is lower than target value,
		// perform Binary Search on the right sub array
		// arr[(mid + 1), ..., end]
		else {
			return Binary_Search(arr, (mid + 1), end, val);
		}
	}

	// Not found
	return -1;
}
