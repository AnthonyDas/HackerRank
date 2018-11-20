#include <vector>
#include <iostream>

// Complete the minimumBribes function below.
void minimumBribes(const std::vector<int> &q) {
	// Set up perfectly ordered queue
	std::vector<int> current;
	for (int i = 0; i < q.size(); ++i) {
		current.push_back(i + 1);
	}

	int bribes = 0;
	for (int i = 0; i < q.size(); ++i) {
		if (q[i] != current[i]) {
			// Bribe one place
			if (q[i] == current[i + 1]) {
				current[i + 1] = current[i];
				current[i] = q[i];
				++bribes;
			}
			// Bribe two places
			else if (q[i] == current[i + 2]) {
				current[i + 2] = current[i + 1];
				current[i + 1] = current[i];
				current[i] = q[i];
				bribes += 2;
			}
			else {
				std::cout << "Too chaotic" << std::endl;
				return;
			}
		}
	}

	std::cout << bribes << std::endl;
}