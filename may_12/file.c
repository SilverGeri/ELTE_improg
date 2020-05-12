#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE* f = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "w");
	if (f == NULL) {
		printf("error while opening the file\n");
		return 1;
	}

	char* line;
	size_t read;
	ssize_t size;

	read = getline(&line, &size, f);
	while(read != -1) {
		printf("%d, %s", read, line);
		fwrite(line, sizeof(char), strlen(line), output);
		read = getline(&line, &size, f);
	}

	fclose(f);
	fclose(output);

	return 0;
}
