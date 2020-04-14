#include <stdio.h>

int factorial(int n) {
	// factorial(5) = 5 * 4 * 3 * 2 * 1
	// factorial(5) = 5 * factorial(4) = 5 * 4 * factorial(3) = ...
	if (n == 1) {
		return 1;
	}
	return n * factorial(n-1);
}

int factorial_tail_recursion_helper(int result, int n) {
	// helper(1, 5) = helper(5, 4) = helper(20, 3) = helper(60, 2) = helper(120, 1)
	if (n == 1) {
		return result;
	}

	return factorial_tail_recursion_helper(result * n, n-1);
}

int factorial_tail_recursion(int n) {
	factorial_tail_recursion_helper(1, n);
}

int factorial_iterative(int n) {
	int retval = 1;
	for (int i = 2; i <= n; ++i) {
		retval *= i;
	}

	return retval;
}


int main() {
	printf("%d\n", factorial(1000));
	printf("%d\n", factorial_tail_recursion(10));
	printf("%d\n", factorial_iterative(10));

}
