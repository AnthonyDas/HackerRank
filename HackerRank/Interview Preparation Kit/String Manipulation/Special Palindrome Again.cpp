#include <string>

// Complete the substrCount function below.
long substrCount(int n, std::string s) {
	long count = 0;

	for (int i = 0; i < n; ++i) {
		// All chars the same
		for (int j = i; j < n; ++j) {
			if (s[i] == s[j]) {
				++count;
				continue;
			}
			break;
		}

		// All chars except middle are the same
		int left = (i - 1), right = (i + 1);

		while (left >= 0 && right < n) {
			if ((s[left] == s[right]) && // left and right the same
				(s[left] == s[i - 1]) && // all left the same (and hence all right the same) 
				(s[left] != s[i])) { // different from middle

				++count;
				--left;
				++right;
				continue;
			}
			break;
		}
	}

	return count;
}