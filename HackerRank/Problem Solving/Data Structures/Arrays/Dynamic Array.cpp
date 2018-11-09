#include <vector>

// Complete the dynamicArray function below.
std::vector<int> dynamicArray(const int &n, const std::vector<std::vector<int> > &queries) {

	std::vector<std::vector<int> > seq(n);
	int lastAnswer = 0;

	std::vector<int> res;
	for (int i = 0; i < queries.size(); ++i) {
		const int type = queries[i][0], x = queries[i][1], y = queries[i][2];

		int index = (x ^ lastAnswer) % n;

		if (type == 1) {
			seq[index].push_back(y);
		}
		else {
			lastAnswer = seq[index][y % seq[index].size()];
			res.push_back(lastAnswer);
		}
	}

	return res;
}