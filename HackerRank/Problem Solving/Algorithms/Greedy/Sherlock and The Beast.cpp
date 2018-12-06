#include <iostream>


// Complete the decentNumber function below.
void decentNumber(int n) {
	int fives_count = n, threes_count = 0;
	while (fives_count % 3 != 0) {
		fives_count -= 5;
		threes_count += 5;
	}

	if (fives_count < 0) {
		std::cout << -1;
	}
	else {
		for (int i = 0; i < fives_count; ++i) {
			std::cout << 5;
		}
		for (int i = 0; i < threes_count; ++i) {
			std::cout << 3;
		}
	}
	std::cout << std::endl;
}
