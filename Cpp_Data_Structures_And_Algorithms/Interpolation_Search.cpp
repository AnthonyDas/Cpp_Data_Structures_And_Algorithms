int Interpolation_Search(int arr[], int low, int high, int val) {
	// Only process if high index is >= low index
	if (low <= high) {

		// mid = low + (diff in value) * (range in index) / (range in value)
		int mid = low + ((val - arr[low]) * (high - low) / (arr[high] - arr[low]));

		// Is the middle value is the target value?
		if (arr[mid] == val) {
			return mid;
		}
		// If the middle value is greater than the target value,
		// then perform Interpolation Search on the left sub array
		// arr[low, ..., (mid - 1)]
		else if (arr[mid] > val) {
			return Interpolation_Search(arr, low, (mid - 1), val);
		}
		// If the middle value is lower than the target value,
		// then perform Interpolation Search on the right sub array
		// arr[(mid + 1), ..., high]
		else {
			return Interpolation_Search(arr, (mid + 1), high, val);
		}
	}

	// Not found
	return -1;
}
