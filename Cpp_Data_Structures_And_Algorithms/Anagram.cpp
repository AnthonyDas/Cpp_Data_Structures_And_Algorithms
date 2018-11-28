#include <string>
#include <algorithm> // transform
#include <cctype> // toupper

bool IsAnagram(std::string str1, std::string str2) {
	// Anagram is not case sensitive so we convert all characters
	// to uppercase
	std::transform(str1.begin(), str1.end(), str1.begin(), toupper);
	std::transform(str2.begin(), str2.end(), str2.begin(), toupper);

	// Anagram does not care about space so remove all spaces if any
	str1.erase(
		std::remove(str1.begin(), str1.end(), ' '),
		str1.end());
	str2.erase(
		std::remove(str2.begin(), str2.end(), ' '),
		str2.end());

	std::sort(str1.begin(), str1.end());
	std::sort(str2.begin(), str2.end());

	// If they both are anagram,
	// they will be exactly same after sorted
	return str1 == str2;
}
