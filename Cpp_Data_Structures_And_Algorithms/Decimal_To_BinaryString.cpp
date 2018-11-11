#include <string>
#include <sstream>

std::string DecimalToBinaryString(int decimalNumber) {
    // Initial result
	std::string binaryString = "0";

    // Only perform this procedure
    // if decimalNumber is greater than 0
    if (decimalNumber > 0) {
        // Reset result
        binaryString.clear();

        while (decimalNumber) {
			std::ostringstream ss{ decimalNumber % 2 };
            binaryString = ss.str() + binaryString;
			decimalNumber /= 2;
        }
    }

    // return the binary string
    return binaryString;
}
