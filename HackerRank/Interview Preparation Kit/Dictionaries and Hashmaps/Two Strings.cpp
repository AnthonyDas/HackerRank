#include <string>
#include <map>

// Complete the twoStrings function below.
std::string twoStrings(std::string s1, std::string s2) {
	// There will be a common substring if there is a common letter
	// within both string s1 and string s1

	std::map<char, int> m;
	for (auto &c : s1) {
		++m[c];
	}
	for (auto &c : s2) {
		if (m[c]) {
			return "YES";
		}
	}

	return "NO";
}