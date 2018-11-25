#include <vector>
#include <iostream>
#include <algorithm> // min, max
#include <utility> // std::pair

bool costs_comp(const std::pair<int, int> &a, const std::pair<int, int> &b) {
	return a.first < b.first;
}


int binary_search(const std::vector<std::pair<int, int> > &costs, const int &start, const int &end, const int &val) {
	if (start <= end) {
		int mid = start + (end - start) / 2;
		if (costs[mid].first == val) {
			return mid;
		}
		else if (costs[mid].first < val) {
			return binary_search(costs, mid + 1, end, val);
		}
		else {
			return binary_search(costs, start, mid - 1, val);
		}
	}
	return -1;
}


// Complete the whatFlavors function below.
void whatFlavors(std::vector<int> cost, int money) {
	std::vector<std::pair<int, int> > costs;
	int index = 0;
	for (auto &c : cost) {
		costs.emplace_back(c, ++index);
	}

	std::sort(costs.begin(), costs.end(), costs_comp);

	for (int i = 0; i < (costs.size() - 1); ++i) {
		int j = binary_search(costs, (i + 1), (costs.size() - 1), (money - costs[i].first));
		if (j >= 0) { // Found it!
			std::cout << std::min(costs[i].second, costs[j].second) << " " 
				<< std::max(costs[i].second, costs[j].second) <<std::endl;
			return;
		}
	}

	// Given solution always exists so should return above
}