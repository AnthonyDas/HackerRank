#include <string>
#include <sstream>

// Complete the superDigit function below.

/* Given an integer, x, the super digit of the integer is:
- If  has only  digit, then its super digit is x.
- Otherwise, the super digit of  is equal to the super digit of the sum of the digits of x. 

Complete the function superDigit in the editor below.
It must return the calculated super digit of p as an integer.

superDigit has the following parameter(s):
- n: a string representation of an integer.
- k: an integer, the times to concatenate n to make p. */
int superDigit(std::string n, int k) {
	// Must use long for digitSum as n < 10^100000 and k <= 10^5
	long digitSum = 0;
	for (auto it = n.cbegin(); it != n.cend(); ++it) {
		digitSum += (*it - '0') * k;
	}

	if (digitSum < 10) {
		return digitSum;
	}

	std::ostringstream stringstream;
	stringstream << digitSum;
	return superDigit(stringstream.str(), 1);
}