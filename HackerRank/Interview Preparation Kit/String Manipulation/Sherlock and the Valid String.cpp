#include <string>
#include <map>

// Complete the isValid function below.
std::string isValid(std::string s) {
	if (s.empty()) {
		return "YES";
	}

	// Char, count
	std::map<char, int> m1;
	for (auto &c : s) {
		++m1[c];
	}

	// Char count, count
	std::map<int, int> m2;
	for (auto &p : m1) {
		++m2[p.second];
	}

	if (m2.size() == 1) {
		// All chars already have same frequency
		return "YES";
	}
	else if (m2.size() == 2) {
		// The difference in frequencies is 1 and the larger frequency only occurs once.
		// E.g. chars either appear six or seven times whilst the seven times only occurs one.
		// In this case, delete one of the seven times char so all chars now appear six times.
		if (abs(m2.begin()->first - m2.rbegin()->first) == 1 &&
			(m2.begin()->first > m2.rbegin()->first ? m2.begin()->second == 1 : m2.rbegin()->second == 1)) {
			return "YES";
		}
		// One char appears once which can be deleted
		if ((m2.begin()->first == 1 && m2.begin()->second == 1) ||
			(m2.rbegin()->first == 1 && m2.rbegin()->second == 1)) {
			return "YES";
		}
	}

	return "NO";
}