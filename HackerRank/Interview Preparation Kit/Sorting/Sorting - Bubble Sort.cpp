#include <vector>
#include <iostream>


void swap(int &lhs, int &rhs) {
	const int temp = lhs;
	lhs = rhs;
	rhs = temp;
}

// Complete the countSwaps function below.
void countSwaps(std::vector<int> a) {
	int count = 0;

	// Start position
	for (int i = 0; i < (a.size() - 1); ++i) {

		// Moving along array left to right 
		for (int j = 0; j < (a.size() - 1 - i); ++j) {

			// Swap adjacent elements if they are in decreasing order
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				++count;
			}
		}
	}

	std::cout << "Array is sorted in " << count << " swaps." << std::endl;
	std::cout << "First Element: " << a.front() << std::endl;
	std::cout << "Last Element: " << a.back() << std::endl;
}