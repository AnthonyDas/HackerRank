#include <string>
#include <algorithm> // min

// Complete the repeatedString function below.
long repeatedString(const std::string &s, long n) {
	long count = 0;

	for (int i = 0; i < std::min(n, (long)s.size()); ++i) {
		if (s[i] == 'a') {
			++count;
		}
	}

	if (n <= s.size()) {
		return count;
	}

	count *= (n / s.size());
	for (int i = 0; i < (n % s.size()); ++i) {
		if (s[i] == 'a') {
			++count;
		}
	}

	return count;
}