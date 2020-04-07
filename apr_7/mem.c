#include <stdio.h>
#include <stdlib.h> // for malloc

int* foo() {
	int* y = (int*)malloc(sizeof(int)); // void* by default
	printf("in foo: %p\n", y);
	return y;
}

int main() {
	int x;
	int *a = foo();
	printf("in main: %p\n", a);

	free(a); // deallocate memory

	int *p = (int*)malloc(sizeof(int));
	int *arr = (int*)malloc(10 * sizeof(int));

	free(p);
	free(arr);

	////////////////////
	int **matrix = (int**)malloc(5 * sizeof(int*));
	for (int i = 0; i < 5; ++i) {
		matrix[i] = (int*)malloc(5 + sizeof(int));

		for (int j = 0; j < 5; ++j) {
			matrix[i][j] = 0;
		}
	}


	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < 5; ++i) {
		free(matrix[i]);
	}
	free(matrix);

	return 0;
}
