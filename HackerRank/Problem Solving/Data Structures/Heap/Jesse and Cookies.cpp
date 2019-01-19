#include <vector>
#include <queue>
#include <functional> // std::greater

// Complete the cookies function below.
int cookies(const int &k, const std::vector<int> &A) {
	std::priority_queue<int, std::vector<int>, std::greater<int> > pq(A.begin(), A.end());

	int count = 0;

	while (pq.size() >= 2 && pq.top() < k) {
		int first = pq.top();
		pq.pop();

		int second = pq.top();
		pq.pop();

		// std::cout << first << " " << second << std::endl;

		int combined = first + (2 * second);
		pq.push(combined);

		++count;
	}

	return pq.top() >= k ? count : -1;
}