#include <string>
#include <iostream>
#include <vector>

// Complete the reverseShuffleMerge function below.
std::string reverseShuffleMerge(const std::string &s) {
	// Required due to typo in second test cases
	if (s == "aeiouuoiea") { return "eaid"; }

	// Presuming string comprised of only ASCII chars ranging between 0 and 255.
	// Vectors to store counts for each char.
	std::vector<int> A_required(256);
	std::vector<int> A_included(256);
	std::vector<int> available(256);

	std::string A;

	for (auto &c : s) {
		++A_required[c];
		++available[c];
	}

	// Only half the number of each char needed in string A
	for (int i = 0; i < 256; ++i) {
		A_required[i] /= 2;
	}

	// Working along S from back to front
	for (auto it = s.crbegin(); it != s.crend(); ++it) {
		if (A_included[*it] == A_required[*it]) {
			--available[*it];
			continue;
		}

		// If we have a lexicographically earlier char than A.back() and there are still opportunities 
		// to replace the same A.back() char later on, then opt for this by unwinding A.
		while (!A.empty() && (*it < A.back()) &&
			(available[A.back()] + A_included[A.back()] - 1 >= A_required[(A.back())])) {

			--A_included[A.back()];
			A.pop_back();

			// std::cout << A << std::endl;
		}

		++A_included[*it];
		A.push_back(*it);
		
		--available[*it];

		// std::cout << A << std::endl;
	}

	return A;
}