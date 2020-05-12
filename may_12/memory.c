#include <stdio.h>
#include <stdlib.h> // for malloc

int get_max(int* arr, int size) {
	printf("sizeof array: %ld, size: %d\n", sizeof(arr), size);

	return 0;
}

int main() {
	int x; // going on the stack, default value is memory garbage
	int *p; // the pointer itself is on the stack
	
	p = (int*)malloc(sizeof(int)); // it allocates memory on thte heap, p points to there, right now it's also memory garbage
	printf("p first: %p: %d\n", p, *p);
//	free(p);
	
	p = (int*)malloc(sizeof(int));
	printf("p second: %p: %d\n", p, *p);

	int* p2 = (int*)malloc(sizeof(int));
	printf("p2: %p: %d\n", p2, *p2);

	p = (int*)realloc(p, 200 * sizeof(int));
	printf("p with realloc: %p: %d\n", p, *p);


	free(p);

	char* str = "sadsad;gljsa;ldgsa\0";

	int asd[] = {12,32,12,423,43,53,54,54,54,54,2};
	get_max(asd, sizeof(asd) / sizeof(int));

	// in C++, we have:
	// std::vector<int> my_vect;
	// my_vect.size();

	return 0;
}
