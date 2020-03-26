#include <stdio.h>


void set_null(int *array, int num) {
	for (int i = 0; i < num; ++i) {
		array[i] = 0;
	}
}

void print_array(const int* array, int size) {
	if (size == 0) {
		printf("[]\n");
		return;
	}

	printf("[");
	for (int i = 0; i < size-1; ++i) {
		printf("%d, ", array[i]);
	}
	printf("%d]\n", array[size-1]);
}


void get_size(int* array) {
	// does not work
	printf("length: %lu\n", sizeof(array) / sizeof(int));
}


void swap(int* lhs, int* rhs) {
	int temp = *lhs;
	*lhs = *rhs;
	*rhs = temp;
}

void swap3(int* x, int* y, int* z) {
	int temp = *x;
	*x = *y;
	*y = *z;
	*z = temp;
}


int main() {
	int x = 1;

	int *p = &x;

	printf("%d, %d\n", x, *p);

	x = 2;
	printf("%d, %d\n", x, *p);

	*p = 3;
	printf("%d, %d\n", x, *p);

	int y = 0;
	p = &y;
	printf("%d, %d\n", x, *p);

	// declaring pointers
	int* a, *d;
	int *b;
	int * c;
	
        printf("array stuff:\n");
	int arr[] = {1,3,3,4,5,5,5,3};
	print_array(arr, sizeof(arr) / sizeof(int));

	set_null(arr, 2);
	print_array(arr, sizeof(arr) / sizeof(int));

	print_array(arr, 3);
	
	get_size(arr);
	
	printf("sizes:\n");
	printf("int %lu\n", sizeof(int));
	printf("int* %lu\n", sizeof(int*));
	printf("float %lu\n", sizeof(float));
	printf("float* %lu\n", sizeof(float*));
	printf("char %lu\n", sizeof(char));
	printf("char* %lu\n", sizeof(char*));
	

	// swap
	int one = 1, two = 2, three = 3;
	printf("one: %d, two: %d\n", one, two);

	swap(&one, &two);
	printf("one: %d, two: %d\n", one, two);

	swap3(&one, &two, &three);
	printf("one: %d, two: %d, three: %d\n", one, two, three);

	return 0;
}
