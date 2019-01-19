#include <iostream>
#include <vector>
#include <algorithm> // std::sort

// Complete the minTime function below.
int minTime(const int &n, std::vector<std::vector<int>> roads,
	const std::vector<int> &machines) {

	// Flag which cities have a machine
	std::vector<bool> mach_present(n, false);
	for (auto &m : machines) {
		mach_present[m] = true;
	}

	// Sort the roads in time descending
	std::sort(roads.begin(), roads.end(),
		[](const std::vector<int> &a, const std::vector<int> &b) {
		return a[2] > b[2];
	});

	int work_time = 0, set_id = 0;
	std::vector<bool> set_has_machine;
	std::vector<int> city_set(n, -1);

	// Read roads and decide which cities can belong in the same set
	for (auto &r : roads) {

		// Neither city visted
		if (city_set[r[0]] == -1 && city_set[r[1]] == -1) {
			if (mach_present[r[0]] && mach_present[r[1]]) {
				// Cannot belong in same set - destroy road
				work_time += r[2];
				city_set[r[0]] = set_id++;
				city_set[r[1]] = set_id++;
				set_has_machine.push_back(true);
				set_has_machine.push_back(true);
			}
			else {
				// Can belong in same set
				city_set[r[0]] = city_set[r[1]] = set_id++;
				set_has_machine.push_back(mach_present[r[0]] || mach_present[r[1]]);
			}
		}
		// First city visted, second not visted OR
		// first city not visted, second visted
		else if ((city_set[r[0]] != -1 && city_set[r[1]] == -1) ||
			(city_set[r[0]] == -1 && city_set[r[1]] != -1)) {

			const int visited = city_set[r[0]] != -1 ? r[0] : r[1];
			const int unvisited = city_set[r[0]] == -1 ? r[0] : r[1];

			if (!mach_present[unvisited]) {
				// Can belong in same set
				city_set[unvisited] = city_set[visited];
			}
			else {
				if (set_has_machine[city_set[visited]]) {
					// Cannot belong in same set - destroy road
					work_time += r[2];
					city_set[unvisited] = set_id++;
					set_has_machine.push_back(true);
				}
				else {
					// Can belong in same set
					city_set[unvisited] = city_set[visited];
					set_has_machine[city_set[visited]] = true;
				}
			}
		}
		// Both cities visted
		else {
			if (set_has_machine[city_set[r[0]]] && set_has_machine[city_set[r[1]]]) {
				// Cannot belong in same set - destroy road
				work_time += r[2];
			}
			else {
				// Merge sets together
				const int from = city_set[r[1]];
				const int to = city_set[r[0]];
				for (auto &v : city_set) {
					if (v == from) {
						v = to;
					}
				}
				set_has_machine[to] = set_has_machine[to] || set_has_machine[from];
				set_has_machine[from] = false;
			}
		}
	}

	return work_time;
}