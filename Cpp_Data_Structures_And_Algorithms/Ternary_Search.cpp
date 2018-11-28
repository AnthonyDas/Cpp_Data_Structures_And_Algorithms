int Ternary_Search(int arr[], int start, int end, int val) {
	// Only process if end index is >= start index
	if (start <= end) {

		const int midLeft = start + (end - start) / 3;

		const int midRight = midLeft + (end - start) / 3;

		// Is midLeft value the target value?
		if (arr[midLeft] == val) {
			return midLeft;
		}
		// Is midRight value the target value?
		else if (arr[midRight] == val) {
			return midRight;
		}
		// If target value smaller than midLeft value,
		// then perform Ternary Search on left subarray
		// arr[start, ..., (midLeft - 1)]
		else if (arr[midLeft] > val) {
			return Ternary_Search(arr, start, (midLeft - 1), val);
		}
		// If target value is greater than midRight value,
		// then perform Ternary Search on right subarray
		// arr[midRight + 1 ... end]
		else if (arr[midRight] < val) {
			return Ternary_Search(arr, (midRight + 1), end, val);
		}
		// Target value must be in between midLeft and midRight,
		// perform Ternary Search on subarray
		// arr[(midLeft + 1), ..., (midRight - 1)]
		else {
			return Ternary_Search(arr, (midLeft + 1), (midRight - 1), val);
		}
	}

	// Not found
	return -1;
}
