#include <string>
#include <map>

// Complete the makeAnagram function below.
int makeAnagram(std::string a, std::string b) {
	std::map<char, int> m;
	for (auto &c : a) {
		++m[c];
	}
	for (auto &c : b) {
		--m[c];
	}

	int count = 0;
	for (auto &p : m) {
		count += abs(p.second);
	}

	return count;
}