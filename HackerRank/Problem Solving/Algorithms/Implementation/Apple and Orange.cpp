#include <iostream>
#include <vector>

// Complete the countApplesAndOranges function below.
void countApplesAndOranges(int s, int t, int a, int b,
	const std::vector<int> &apples, const std::vector<int> &oranges) {
	// s: integer, starting point of Sam's house location.
	// t: integer, ending location of Sam's house location.
	// a: integer, location of the Apple tree.
	// b: integer, location of the Orange tree

	int apple_hits = 0, orange_hits = 0;

	for (std::vector<int>::const_iterator it = apples.cbegin(); it != apples.cend(); ++it) {
		if ((a + *it) >= s && (a + *it) <= t) {
			++apple_hits;
		}
	}
	std::cout << apple_hits << std::endl;

	for (std::vector<int>::const_iterator it = oranges.cbegin(); it != oranges.cend(); ++it) {
		if ((b + *it) >= s && (b + *it) <= t) {
			++orange_hits;
		}
	}
	std::cout << orange_hits << std::endl;
}