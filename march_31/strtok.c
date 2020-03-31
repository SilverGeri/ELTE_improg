#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {
	FILE *fp;
	fp = fopen("input.txt", "r");
	size_t len;
	int read;
	char* line = NULL;

	int count = 1;
	while ((read = getline(&line, &len, fp)) != -1) {
		printf("%d. line with %d characters: %s", count, read, line);
		++count;
	}

	fclose(fp);


	count = 1;
	char input[] = "some more words";
	char* word = strtok(input, " ");
	while (word) {
		printf("%d. %s\n", count, word);
		word = strtok(NULL, " ");
		++count;
	}

	return 0;
}
