#include <stdio.h>


int main() {
	int a = 5;
	a = 3;

	const int b = 1;
	// b = 2; // error
	
	const int* p = &b;
	// *p = 2; // error
	p = &a;

	int* const r = &a;
	*r = 3;
	r = &a;
	
	const int* ap = &a;
	// *ap = 3; // error
	

	int* bp = &b;
	*bp = 1;




	return 0;
}
