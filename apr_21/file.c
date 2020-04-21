#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]) {
	if (argc < 3) {
		printf("Not enough parameters\n");
		return 1;
	}

	int n = atoi(argv[1]);
	FILE* fp = NULL;

	fp = fopen(argv[2], "r");
	if (fp == NULL) {
		printf("No such file\n");
		return 1;
	}

	char* line = NULL;
	size_t len = 0;
	ssize_t read = 0;

	for (int i = 0; i < n-1; ++i) {
		read = getline(&line, &len, fp);
		printf("%p\n", line);
	}
	read = getline(&line, &len, fp);
	printf("line length: %ld, buffer length: %ld\n", read, len);
	printf("%dth line is %s\n", n, line);

	free(line);

	return 0;

}
