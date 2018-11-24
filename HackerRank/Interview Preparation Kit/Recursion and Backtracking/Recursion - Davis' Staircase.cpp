#include <map>
#include <utility> // std::pair

// Complete the stepPerms function below.
// Think of n as steps remaining
int stepPerms(int n) {
	static std::map<int, int> cache;
	std::map<int, int>::const_iterator it = cache.find(n);
	if (it != cache.end()) {
		return it->second;
	}

	if (n == 0) {
		return 1; // Found another way
	}

	int count = 0;

	// Recursive calls using 3, 2 and 1 sized steps
	if (n >= 3) {
		count += stepPerms(n - 3);
	}
	if (n >= 2) {
		count += stepPerms(n - 2);
	}
	if (n >= 1) {
		count += stepPerms(n - 1);
	}

	cache.insert(std::pair<int, int>(n, count));

	return count;
}