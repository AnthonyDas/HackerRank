#include <string>

// Complete the kangaroo function below.
std::string kangaroo(int x1, int v1, int x2, int v2) {
	// Constraints x1 < x2 
	if (v2 >= v1) {
		return "NO";
	}

	return (x2 - x1) % (v1 - v2) == 0 ? "YES" : "NO";
}