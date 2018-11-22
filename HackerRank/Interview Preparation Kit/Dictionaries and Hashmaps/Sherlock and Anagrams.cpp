#include <string>
#include <map>
#include <vector>
#include <sstream>

// Complete the sherlockAndAnagrams function below.
int sherlockAndAnagrams(std::string s) {
	int count = 0;

	for (int len = 1; len < s.size(); ++len) {
		std::vector<std::map<char, int> > subs;

		for (int pos = 0; pos < (s.size() - len + 1); ++pos) {

			const std::string sub = s.substr(pos, len);
			std::map<char, int> m;
			for (auto &c : sub) {
				++m[c];
			}
			subs.push_back(m);
		}

		for (int i = 0; i < subs.size() - 1; ++i) {
			for (int j = i + 1; j < subs.size(); ++j) {
				if (subs[i] == subs[j]) {
					++count;
				}
			}
		}
	}

	return count;
}