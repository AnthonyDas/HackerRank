#include <vector>

// Complete the chiefHopper function below.
int chiefHopper(const std::vector<int> &arr) {
	int energy = 0;

	for (std::vector<int>::const_reverse_iterator rit = arr.rbegin(); rit != arr.rend(); ++rit) {
		energy = (int)ceil((energy + *rit) / 2.0);
	}

	return energy;
}