#include <string>

// Complete the alternatingCharacters function below.
int alternatingCharacters(std::string s) {
	int count = 0;
	if (!s.empty()) {
		char last = s.front();
		for (auto it = s.begin() + 1; it != s.end(); ++it) { // NB. begin() + 1
			if (*it == last) {
				++count;
			}
			else {
				last = *it;
			}
		}
	}
	return count;
}