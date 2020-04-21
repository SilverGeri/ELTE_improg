#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* find_space(char* str) {
	if (strlen(str) == 0) {
		return NULL;
	}
	int i = 0;
	while (i < strlen(str) && str[i] != ' ') {
		++i;
	}
	if (i < strlen(str)) {
		return &str[i];
	}

	return NULL;
}

int main() {
	char hello_stack[] = "hello world";
	static char hello_static[] = "helloworld";
	char* hello_heap = (char*)malloc(strlen(hello_stack));
	strcpy(hello_heap, "hello world");

	printf("%p\n", find_space(hello_stack));
	printf("%p\n", find_space(hello_static));
	printf("%p\n", find_space(hello_heap));
	
	free(hello_heap);

	return 0;
}
