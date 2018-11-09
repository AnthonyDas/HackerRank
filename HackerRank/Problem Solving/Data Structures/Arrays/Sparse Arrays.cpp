#include <vector>
#include <string>
#include <map>

// Complete the matchingStrings function below.
std::vector<int> matchingStrings(const std::vector<std::string> &strings, const std::vector<std::string> &queries) {
	std::map<std::string, int> m; // string, count

	for (int i = 0; i < strings.size(); ++i) {
		++m[strings[i]];
	}

	std::vector<int> res;
	for (int i = 0; i < queries.size(); ++i) {
		std::map<std::string, int>::const_iterator it = m.find(queries[i]);
		if (it == m.end()) {
			res.push_back(0);
		}
		else {
			res.push_back(it->second);
		}
	}

	return res;
}