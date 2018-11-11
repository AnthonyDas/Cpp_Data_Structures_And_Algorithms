#include <vector>

std::vector<int> SearchPattern(std::string targetString, std::string patternString) {
	std::vector<int> vecIndex;

	// Retrieve string length
	const int strLen = targetString.size();
	const int patLen = patternString.size();

	// Only perform the following procedure
	// if pattern string is not longer than target string
	if (patLen <= strLen) {
		// Iterate through target string elements
		// from the beginning until
		// the last possible element where
		// pattern is at the last position
		for (int i = 0; i <= (strLen - patLen); ++i) {
			int j;

			// Start comparing pattern string
			for (j = 0; j < patLen; ++j) {
				// Quit from inner for-loop
				// if character is not matched
				if (targetString[i + j] != patternString[j]) {
					break;
				}
			}

			// If inner for-loop is done it means that
			// pattern is found in the target string
			if (j == patLen) {
				vecIndex.push_back(i);
			}
		}
	}

	return vecIndex;
}
