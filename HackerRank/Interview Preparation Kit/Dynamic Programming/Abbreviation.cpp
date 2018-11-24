#include <string>
#include <unordered_map>

bool abbreviation(std::string a, std::string b, std::unordered_map<int, bool> &cache) {
	const int key = (a.size() * 10000) + b.size();
	auto it = cache.find(key);
	if (it != cache.end()) {
		return it->second;
	}

	bool res = true;

	if (b.empty() && a.empty()) {
		// Do nothing
	}
	else if (b.empty() && !a.empty()) {
		for (auto &ch : a) {
			if (isupper(ch)) {
				res = false;
			}
		}
	}
	else if (!b.empty() && a.empty()) {
		res = false;
	}
	else { // !b.empty() && !a.empty()
		if (isupper(a.back())) {
			if (a.back() == b.back()) {
				a.pop_back();
				b.pop_back();
				res = abbreviation(a, b, cache);
			}
			else {
				res = false;
			}
		}
		else { // islower(a.back())
			if (toupper(a.back()) == b.back()) {
				a.pop_back();
				std::string c(b);
				c.pop_back();
				res = abbreviation(a, b, cache) || abbreviation(a, c, cache);
			}
			else {
				a.pop_back();
				res = abbreviation(a, b, cache);
			}
		}
	}

	cache[key] = res;

	return res;
}

// Complete the abbreviation function below.
bool abbreviation(std::string a, std::string b) {
	std::unordered_map<int, bool> cache;
	return abbreviation(a, b, cache);
}