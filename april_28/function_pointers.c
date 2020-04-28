#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


bool is_prime(int n) {
	// this implementation can be improved

	if (n < 0) {
		n *= -1;
	}

	if (n < 2) {
		return false;
	}

	for (int i = 2; i <= n / 2; ++i) {
		if (n % i == 0) {
			return false;
		}
	}

	return true;
}

bool is_even(int n) {
	return n % 2 == 0;
}

int count(int* arr, int size, bool (*predicate)(int)) {
	int result = 0;
	for (int i = 0; i < size; ++i) {
		if ((*predicate)(arr[i])) {
			++result;
		}
	}

	return result;
}

/*
Create a function which gets an array parameter and finds the first element which meets a specific condition.
This condition can be given as a function parameter too with a boolean function. Fir example find the first word
in the array which is longer than 5 characters and return a pointer which points to this word.
In case there is no long word in the array, then return NULL.
*/

int main() {
	// already studied pointers
	int x = 5;
	int *p = &x;

	int data[] = {1,2,3,4,5,65,6,7,7,8,8,8};
	
	bool (*f_ptr)(int) = &is_prime;

	// printf("%d, %d\n", is_prime(1), (*f_ptr)(1));
	
	printf("prime numbers in my array: %d\n", count(data, sizeof(data) / sizeof(int), &is_prime));
	printf("even numbers in my array: %d\n", count(data, sizeof(data) / sizeof(int), &is_even));

	return 0;
}


