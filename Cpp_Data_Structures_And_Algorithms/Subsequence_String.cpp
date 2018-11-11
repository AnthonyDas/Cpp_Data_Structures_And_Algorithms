#include <string>

// Check if 1st string is a subsequence of 2nd string.
// NB. Subsequence is different from substring. A subsequence
// does not require chars to be consecutive chars within source. 
bool IsSubSequence(std::string str1, std::string str2, int x, int y) {
    // If all characters in str1 have been checked,
    // it means that the str1 is subsequence of str2
    if (x == 0) {
        return true;
    }

    // There is some characters in str2
    // that don't matched with str1 so return false
    if (y == 0) {
        return false;
    }

    // If characters of two strings are matching,
    // continue to check another character
    if (str1[x - 1] == str2[y - 1]) {
        return IsSubSequence(str1, str2, x - 1, y - 1);
    }
    // If not, check the second last of str2
    else {
        return IsSubSequence(str1, str2, x, y - 1);
    }
}
