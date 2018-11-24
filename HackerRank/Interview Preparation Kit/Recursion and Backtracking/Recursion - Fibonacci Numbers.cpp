// Complete the function.
int fibonacci(int n) {
	if (n == 1) { return 1; }
	else if (n == 0) { return 0; }

	return fibonacci(n - 1) + fibonacci(n - 2);
}


// Without recursion
int fibonacci2(int n) {
	int x = 0, y = 1, i = 1;
	while (i < n) {
		int z = x + y;
		x = y;
		y = z;
		++i;
	}
	return y;
}