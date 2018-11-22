#include <vector>
#include <map>
#include <iostream>

// Complete the checkMagazine function below.
void checkMagazine(const std::vector<std::string> &magazine, const std::vector<std::string> &note) {
	std::map<std::string, int> m;
	for (auto &s : magazine) {
		++m[s];
	}

	for (auto &s : note) {
		auto it = m.find(s);
		if (it == m.end() || it->second < 1) {
			std::cout << "No" << std::endl;
			return;
		}
		--(it->second);
	}

	std::cout << "Yes" << std::endl;
}