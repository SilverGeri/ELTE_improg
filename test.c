#include <stdlib.h>

struct Foo {
	char* x;
};

int main() {
	struct Foo foo;
	foo.x = (char*)realloc(NULL, 5);
	struct Foo foo2;
	foo2.x = (char*)malloc(5);
	//foo2 = foo;
	free(foo.x);
	free(foo2.x);
}
