#include <string>
#include <algorithm>


bool IsPalindrome(std::string str) {
    // Palindrome is not case sensitive so we convert
	// all characters to uppercase
    transform(str.begin(), str.end(), str.begin(), ::toupper);

    // Palindrome does not care about space
    // so we remove all spaces if any
    str.erase(
        remove(str.begin(), str.end(), ' '),
		str.end());

    // Starting from leftmost and rightmost elements of the str
    int left = 0;
    int right = str.length() - 1;

    // Comparing the current leftmost
    // and rightmost elements
    // until all elements are checked or
    // until unmatched characters are found
    while (right > left) {
        if (str[left++] != str[right--]) {
            return false;
        }
    }

    // If all characters which are compared
    // are same, it must be palindrome
    return true;
}

