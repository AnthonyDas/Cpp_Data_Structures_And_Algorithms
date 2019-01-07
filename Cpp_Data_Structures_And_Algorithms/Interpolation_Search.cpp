int Interpolation_Search(int arr[], const int &start, const int &end, const int &val) {
	// Only process if start index <= end index
	if (start <= end) {

		// mid = start + (diff in value) * (range in index) / (range in value)
		const int mid = start + ((val - arr[start]) * (end - start) / (arr[end] - arr[start]));

		// Is middle value the target value?
		if (arr[mid] == val) {
			return mid;
		}
		// If the middle value is greater than the target value,
		// then perform Interpolation Search on the left sub array
		// arr[start, ..., (mid - 1)]
		else if (arr[mid] > val) {
			return Interpolation_Search(arr, start, (mid - 1), val);
		}
		// If the middle value is lower than the target value,
		// then perform Interpolation Search on the right sub array
		// arr[(mid + 1), ..., end]
		else {
			return Interpolation_Search(arr, (mid + 1), end, val);
		}
	}

	// Not found
	return -1;
}
