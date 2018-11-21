#include <string>

struct Player {
	int score;
	std::string name;
};

class Checker {
public:

	// complete this method
	static int comparator(const Player &a, const Player &b) {
		// 1. Sort by decreasing score
		if (a.score != b.score) {
			return a.score > b.score ? 1 : -1;
		}
		// 2. Sort alphabetically ascending by name 
		return a.name < b.name ? 1 : -1;
	}
};