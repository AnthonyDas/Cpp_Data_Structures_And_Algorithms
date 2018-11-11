int Interpolation_Search(int arr[], int lowIndex, int highIndex, int val) {
	if (lowIndex <= highIndex) {
		// Find middle index
		int middleIndex =
			lowIndex + (
			(val - arr[lowIndex]) * (highIndex - lowIndex) /
				(arr[highIndex] - arr[lowIndex]));

		// If the middle index's value is the searched value
		// then return the index
		if (arr[middleIndex] == val) {
			return middleIndex;
		}
		// If the middle index's value is greater than the searched value
		// then perform another Interpolation Search to the left sub array
		// arr[lowIndex ... middleIndex - 1]
		else if (arr[middleIndex] > val) {
			return Interpolation_Search(arr, lowIndex, middleIndex - 1, val);
		}
		// If the middle index's value is lower than the searched value
		// then perform another Interpolation Search to the right sub array
		// arr[middleIndex + 1 ... highIndex]
		else {
			return Interpolation_Search(arr, middleIndex + 1, highIndex, val);
		}
	}

	// Just in case no any value found
	return -1;
}
