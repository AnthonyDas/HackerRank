#include <vector>
#include <map> 
#include <algorithm> // min

// Complete the beautifulPairs function below.
int beautifulPairs(std::vector<int> A, std::vector<int> B) {
	// Vectors A and B are the same size
	std::map<int, int> m1, m2;
	for (int i = 0; i < A.size(); ++i) {
		++m1[A[i]];
		++m2[B[i]];
	}

	int count = 0;
	for (std::map<int, int>::iterator it_i = m1.begin(); it_i != m1.end(); ++it_i) {
		std::map<int, int>::iterator it_j = m2.find(it_i->first);
		if (it_j != m2.end()) {
			int pairs = std::min(it_i->second, it_j->second);
			count += pairs;
		}
	}

	// Now we have to change an element of B. If we can already form
	// the maximum number of pairs, namely A.size(), then changing any
	// element of B will destroy a beautiful pair. Conversely, if we 
	// don't have the maximum number of pairs, we can change an element
	// B to create a new beautiful pair.  
	return count + (count == A.size() ? -1 : 1);
}