int Ternary_Search(int arr[], const int &start, const int &end, const int &val) {
	// Only process if start index <= end index
	if (start <= end) {

		const int third = (end - start) / 3;
		const int left = start + third;
		const int right = left + third;

		// Is left value the target value?
		if (arr[left] == val) {
			return left;
		}
		// Is right value the target value?
		else if (arr[right] == val) {
			return right;
		}
		// If target value smaller than left value,
		// then perform Ternary Search on left subarray
		// arr[start, ..., (left - 1)]
		else if (arr[left] > val) {
			return Ternary_Search(arr, start, (left - 1), val);
		}
		// If target value is greater than right value,
		// then perform Ternary Search on right subarray
		// arr[(right + 1), ..., end]
		else if (arr[right] < val) {
			return Ternary_Search(arr, (right + 1), end, val);
		}
		// Target value must be in between left and right,
		// perform Ternary Search on subarray
		// arr[(left + 1), ..., (right - 1)]
		else {
			return Ternary_Search(arr, (left + 1), (right - 1), val);
		}
	}

	// Not found
	return -1;
}
