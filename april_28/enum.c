#include <stdio.h>


enum Color { BLUE=1, GREEN=2, YELLOW=4, RED=8, BLACK };

char* colorToString(int color) {
	if (color == BLUE) {
		return "blue";
	} else if (color == GREEN) {
		return "green";
	} else if (color == YELLOW) {
		return "yellow";
	} else if (color == RED) {
		return "red";
	} else if (color == BLACK) {
		return "black";
	} else {
		return "unknown";
	}
}

enum status { OK, OUTOFMEMORY, EMPTY, FULL };

void foo(int x, int* error) {
	// do something
	if (x < 1) {
		*error = EMPTY;
	} else if (x >= 10) {
		*error=  FULL;
	} else {
		*error = OK;
	}
}

int main() {

	printf("The sky is %d\n", BLUE);
	printf("The lemon is %d\n", YELLOW);
	printf("My heart is %d\n", BLACK);

	int error;
	foo(5, &error);

	if (error == OK) {
		printf("everything is fine\n");
	} else if (error == EMPTY) {
		printf("something is empty\n");
	}
	//.... so on
	//
	
	if (OUTOFMEMORY == BLUE) {
		printf("out of memory is blue\n");
	}

	printf("The sky is %s\n", colorToString(BLUE));

	return 0;
}
