#include <string>

// Complete the countingValleys function below.

/* hikes start and end at sea level and each step up or down represents
a  unit change in altitude. We define the following terms:
- A mountain is a sequence of consecutive steps above sea level, starting
with a step up from sea level and ending with a step down to sea level.
- A valley is a sequence of consecutive steps below sea level, starting
with a step down from sea level and ending with a step up to sea level. */
int countingValleys(int n, const std::string &s) {
	int count = 0, height = 0;

	for (std::string::const_iterator it = s.cbegin(); it != s.cend(); ++it) {
		if (*it == 'U') {
			++height;
		}
		else {
			--height;
		}
		if (height == 0 && *it == 'U') {
			++count;
		}
	}

	return count;
}