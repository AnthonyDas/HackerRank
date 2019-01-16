#include <vector>

std::vector<int> gradingStudents(const std::vector<int> &grades) {
	std::vector<int> res;
	for (std::vector<int>::const_iterator it = grades.cbegin(); it != grades.cend(); ++it) {
		if (*it < 38 || *it % 5 < 3) {
			res.push_back(*it);
		}
		else {
			res.push_back(*it + (5 - *it % 5));
		}
	}

	return res;
}