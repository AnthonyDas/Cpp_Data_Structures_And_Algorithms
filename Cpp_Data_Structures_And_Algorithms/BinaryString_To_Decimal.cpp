// Project: BinaryString_To_Decimal.cbp
// File   : BinaryString_To_Decimal.cpp

#include <string>

int BinaryStringToDecimal(std::string binaryString) {
    // Initial result
    int decNumber = 0;

    // variable for current power base
    int pow = 1;

    // Iterate all characters in binaryString
    // from the last character to the first character
    for (std::string::reverse_iterator it = binaryString.rbegin(); it != binaryString.rend(); ++it) {
        // if char '1' is found add decNumber with power of current base
        if (*it == '1') {
           decNumber += pow;
        }

		pow *= 2;
    }

    return decNumber;
}
