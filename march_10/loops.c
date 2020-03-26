#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int args, char* argv[]) {
	for (int i = 0; i < args; ++i) {
		printf("%d\n", i);
	}
	
	time_t t;
	srand((unsigned) time(&t));
	int even = rand();

	while( even % 2 != 0) {
		even = rand();
	}

	printf("%d is an even number\n", even);

}
