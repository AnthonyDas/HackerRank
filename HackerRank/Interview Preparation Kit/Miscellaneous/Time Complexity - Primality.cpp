#include <string>

// Complete the primality function below.
std::string primality(int n) {
	if (n < 2) {
		return "Not prime";
	}
	if (n != 2 && n % 2 == 0) {
		return "Not prime";
	}
	if (n != 3 && n % 3 == 0) {
		return "Not prime";
	}

	// All primes greater than 3 can be written in the form 6k +/- 1.
	for (int i = 5; i*i <= n; i += 6) { // Increment by 6
		if (n % i == 0 || n % (i + 2) == 0) {
			return "Not prime";
		}
	}
	return "Prime";
}