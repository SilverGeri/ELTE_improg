#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // for true and false
#include <math.h>

bool q_e_solver(double a, double b, double c, double* res_1, double* res_2) {
	double under_sqrt = b * b - 4 * a * c;
	if (under_sqrt < 0) {
		return false;
	} else if (under_sqrt == 0) {
		*res_1 = -b / (a * 2);
		*res_2 = -b / (a * 2);
	} else {
		double temp = sqrt(under_sqrt);
		*res_1 = (-b + temp) / (a * 2);
		*res_2 = (-b - temp) / (a * 2);
	}

	return true;
}

void divisible_generator(int n, int* result_arr) {
	static int step = 1;
	int temp = 0;
	for (int i = 0; i < n; ++i) {
		result_arr[i] = temp;
		temp += step;
	}

	++step;
}

int main(int argc, char* argv[]) {
	for (int i = 0; i < argc; ++i) {
		printf("%s\n", argv[i]);
	}

	double res_1 = 0.0, res_2 = 0.0;
	int result;
	result = q_e_solver(2.0, 3.0, 1.0, &res_1, &res_2); // homework: get the coefficients from command line argument
	if (result) {
		printf("solutions: %f, %f\n", res_1, res_2);
	} else {
		printf("the equation has no solution\n");
	}

	printf("\n\ngenerator:\n");
	int n = 10;
	int array[n];
	divisible_generator(n, array);
	for (int i = 0; i < n; ++i) {
		printf("%d, ", array[i]);
	}
	printf("\n");

	divisible_generator(n, array);
	for (int i = 0; i < n; ++i) {
		printf("%d, ", array[i]);
	}
	printf("\n");

	divisible_generator(n, array);
	for (int i = 0; i < n; ++i) {
		printf("%d, ", array[i]);
	}
	printf("\n");

	return 0;
}
