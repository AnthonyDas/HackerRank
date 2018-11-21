#include <vector>
#include <map>
#include <iostream>

// Complete the activityNotifications function below.
int activityNotifications(std::vector<int> expenditure, int d) {
	int notice_count = 0;

	// Employing counting sort and storing counts within a map
	std::map<int, int> trailDays;
	for (int i = 0; i < d; ++i) { // First d days
		++trailDays[expenditure[i]];
	}

	for (int i = d; i < expenditure.size(); ++i) {
		// Replace oldest trailing day with latest trailing day AFTER first iteration
		if (i != d) {
			--trailDays[expenditure[i - (d + 1)]];
			++trailDays[expenditure[i - 1]];
		}

		// When d is odd, median is value at cumulative count (d / 2) + 1 of the sorted values.
		// When d is even, median is average of value at cumulative count
		// (d / 2) and (d / 2) + 1 of the sorted values.
		const int median_pos1 = (d / 2);
		const int median_pos2 = (d / 2) + 1;

		double median = 0.0;
		int count = 0;
		for (auto it = trailDays.cbegin(); it != trailDays.cend(); ++it) {
			if (d % 2 == 0) {
				if (count < median_pos1 && (count + it->second) >= median_pos1) {
					median += it->first;
				}
			}
			if (count < median_pos2 && (count + it->second) >= median_pos2) {
				median += it->first;
				break;
			}
			
			count += it->second;
		}

		// std::cout << i << " " << ((d % 2 == 0) ? (median / 2) : median) << std::endl;

		// If (d % 2 == 0) then we have to div by 2 to calc median
		if (expenditure[i] >= (((d % 2 == 0) ? 1 : 2) * median)) {
			++notice_count;
		}
	}

	return notice_count;
}