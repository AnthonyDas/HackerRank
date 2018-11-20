#include <iostream>
#include <vector>

void left_rotation(const std::vector<int> &a, const int &d) {

	for (int i = 0; i < a.size(); ++i) {
		const int index = (i + d) % a.size();
		std::cout << a[index] << " ";
	}

}