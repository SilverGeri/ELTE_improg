#include <stdio.h>

void print_hello() {
	printf("hello");
}


int max_from_array(int *parameter, int size) {
	int return_value = parameter[0];
	for (int i = 0; i < size; ++i) {
		if (parameter[i] > return_value) {
			return_value = parameter[i];
		}
	}

	return return_value;
}



int main() {
	int array[] = {1, 500};

	printf("element with index 1 is: %d\n", array[1]);

	/*print_hello();
	print_hello();
	print_hello();
	print_hello();
	print_hello();
	print_hello();
	print_hello();
	print_hello();*/
	
	
	int max_value = max_from_array(array, sizeof(array) / sizeof(int)); // call the function

	printf("maximum is %d\n", max_value);

	return 0;
	
}
