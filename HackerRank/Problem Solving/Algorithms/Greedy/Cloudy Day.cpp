#include <vector>
#include <unordered_set>
#include <algorithm> // sort, max
#include <utility> // make_pair

// Return the maximum number of people that will be in
// a sunny town after removing exactly one cloud.
long long int maximumPeople(const std::vector<int> &town_pop, const std::vector<int> &town_loc,
	const std::vector<int> &cloud_loc, const std::vector<int> &cloud_range) {

	// Pair up town population with corresponding town location.
	std::vector<std::pair<int, int> > towns;
	for (int i = 0; i < (int)town_pop.size(); ++i) {
		towns.push_back(std::make_pair(town_pop[i], town_loc[i]));
	}

	// Sort by town_loc asc, then town_pop asc
	auto loc_asc_pop_asc = [](const std::pair<int, int> &i, const std::pair<int, int> &j) {
		return (i.second != j.second) ? i.second < j.second : i.first < j.first; };
	std::sort(towns.begin(), towns.end(), loc_asc_pop_asc);

	// Store cloud start and end positions along with cloud id,
	// (+ve for start, -ve for end, +1 offset to avoid +0 and -0).
	std::vector<std::pair<int, int> > cloud_changes;
	for (int i = 0; i < (int)cloud_loc.size(); ++i) {
		cloud_changes.push_back(std::make_pair((cloud_loc[i] - cloud_range[i]), (i + 1)));
		// Note that the cloud gets removed one position AFTER the end
		cloud_changes.push_back(std::make_pair((cloud_loc[i] + cloud_range[i]) + 1, -(i + 1)));
	}

	// Sort by cloud position asc, then cloud id asc
	auto pos_asc_id_asc = [](const std::pair<int, int> &i, const std::pair<int, int> &j) {
		return (i.first != j.first) ? i.first < j.first : i.second < j.second; };
	std::sort(cloud_changes.begin(), cloud_changes.end(), pos_asc_id_asc);

	// clouds_pop - the total population covered by a single cloud
	std::vector<long long int> clouds_pop(cloud_loc.size());
	std::unordered_set<int> clouds_covering;

	long long int sunny = 0, sunny_after_removal = 0;

	// Iterate through each town and work out which clouds cover it
	auto it = cloud_changes.cbegin();
	for (const auto &town : towns) {

		while (it != cloud_changes.cend() && it->first <= town.second) {
			if (it->second > 0) {
				clouds_covering.insert(it->second);
			}
			else {
				clouds_covering.erase(-(it->second));
			}
			++it;
		}

		// Is town sunny as not covered by any clouds?
		if (clouds_covering.empty()) {
			sunny += town.first;
		}
		// Town only covered by a single cloud that could be removed
		else if (clouds_covering.size() == 1) {
			sunny_after_removal =
				std::max(sunny_after_removal, (clouds_pop[*(clouds_covering.begin()) - 1] += town.first));
		}
	}

	return sunny + sunny_after_removal;
}