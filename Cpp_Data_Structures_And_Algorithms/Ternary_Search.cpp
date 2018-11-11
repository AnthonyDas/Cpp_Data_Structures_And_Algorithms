int Ternary_Search(int arr[], int startIndex, int endIndex, int val) {
	// Only perform searching process
	// if the end index is higher than
	// or equals to start index
	if (startIndex <= endIndex) {
		// Find index of area of the first third
		int middleLeftIndex = startIndex + (endIndex - startIndex) / 3;

		// Find index of area of the last third
		int middleRightIndex = middleLeftIndex + (endIndex - startIndex) / 3;

		// If val is at middleLeftIndex
		// then return middleLeftIndex
		if (arr[middleLeftIndex] == val) {
			return middleLeftIndex;
		}
		// If val is at middleRightIndex
		// then return middleRightIndex
		else if (arr[middleRightIndex] == val) {
			return middleRightIndex;
		}
		// If val is at the are of the first third
		// then perform another Ternary Search to this subarray
		// arr[startIndex ... middleLeftIndex - 1]
		else if (arr[middleLeftIndex] > val) {
			return Ternary_Search(arr, startIndex, middleLeftIndex - 1, val);
		}
		// If val is at the area of the last third
		// then perform another Ternary Search to this subarray
		// arr[middleRightIndex + 1 ... endIndex]
		else if (arr[middleRightIndex] < val) {
			return Ternary_Search(arr, middleRightIndex + 1, endIndex, val);
		}
		// The val is at the area
		// between middleLeftIndex and middleRightIndex
		// arr[middleLeftIndex + 1 ... middleRightIndex - 1]
		else {
			return Ternary_Search(arr, middleLeftIndex + 1, middleRightIndex - 1, val);
		}
	}

	// Just in case no any value found
	return -1;
}
