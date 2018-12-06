#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // sort, min

int teamFormation() {

	int tests;
	std::cin >> tests;

	while (tests--) {
		int n;
		std::cin >> n;

		std::vector<int> skills;
		for (int i = 0; i < n; ++i) {
			int skill;
			std::cin >> skill;

			skills.push_back(skill);
		}

		if (n == 0 || n == 1) {
			std::cout << n << std::endl;
			continue;
		}

		std::sort(skills.begin(), skills.end()); // Skills sorted asc

		std::list<std::pair<int, int> > teams; // Size and greatest skill level

		for (auto &skill : skills) { 
			bool found_team = false;

			for (auto it = teams.begin(); it != teams.end(); ++it) {
				// Consecutive skill level - can go in same team
				if ((it->second + 1) == skill) {
					++(it->first);
					++(it->second);
					found_team = true;
					break;
				}
				else if ((it->second + 1) < skill) {
					break;
				}
			}

			// If no team found for current skill - create new team
			if (!found_team) {
				// NB. push_front() so that teams are sorted:
				// largest skill, followed by smallest size first
				teams.push_front(std::pair<int, int>(1, skill));
			}

			// Sort teams: largest skill, followed by smallest size first
			/* auto skill_desc_size_asc = [](const std::pair<int, int> &i, const std::pair<int, int> &j) {
				return i.second != j.second ? i.second > j.second : i.first < j.first; };
			teams.sort(skill_desc_size_asc); */
		}

		int smallest = INT32_MAX;
		for (auto &team : teams) {
			smallest = std::min(smallest, team.first);
		}
		std::cout << smallest << std::endl;
	}

	return 0;
}