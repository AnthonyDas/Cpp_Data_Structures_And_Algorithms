int Binary_Search(int arr[], int startIndex, int endIndex, int val) {
	// Only perform searching process
	// if the end index is higher than
	// or equals to start index
	if (startIndex <= endIndex) {
		// Find middle index
		int middleIndex = startIndex + (endIndex - startIndex) / 2;

		// If the middle index's value is the searched value
		// then return the index
		if (arr[middleIndex] == val) {
			return middleIndex;
		}
		// If the middle index's value is greater than the searched value
		// then perform another Binary Search to the left sub array
		// arr[startIndex ... middleIndex - 1]
		else if (arr[middleIndex] > val) {
			return Binary_Search(arr, startIndex, middleIndex - 1, val);
		}
		// If the middle index's value is lower than the searched value
		// then perform another Binary Search to the left sub array
		// arr[middleIndex + 1 ... endIndex]
		else {
			return Binary_Search(arr, middleIndex + 1, endIndex, val);
		}
	}

	// Just in case no any value found
	return -1;
}
