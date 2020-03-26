#include <stdio.h>
#include <stdlib.h>

int main(int args, char* argv[]) {
	for (int i = 1; i < args; ++i) {
		printf("%s\n", argv[i]);
	}

	for (int i = 0; i < atoi(argv[1]); ++i) {
		printf("hello\n");
	}

	int intarr[] = {1,2,3,4};
	int array[3];
	// int asdf[]; // invalid!!!

	printf("sizeof int array: %lu\n", sizeof(array));
	
	char chararr[3];

	printf("sizeof char array: %lu\n", sizeof(chararr));

	return 0;
}
