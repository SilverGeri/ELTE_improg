#include <stdio.h>
#include <string.h>


int strlen2(const char* const arr) {
	int len = 0;
	while (arr[len] != '\0') {
		++len;
	}

	return len;
}

void strcpy2(char* target, const char* const source) {
	int i = 0;
	while (source[i] != '\0') {
		target[i] = source[i];
		++i;
	}
	target[i] = '\0';

}

void strcpy3(char* t, const char* s) {
	while (*t++ = *s++);
}

// t: something\0___ s: something\0


void reverse(char* str) {
	int len = strlen(str);
	if (len < 2) return;
	
	for (int i = 0; i < len/2; ++i) {
		char temp = str[i];
		str[i] = str[len-1-i];
		str[len-1-i] = temp;
	}
}

// asdfg
// gsdfa
// gfdsa
// gfdsa


int strcmp2(char* lhs, char* rhs) {
	int i = 0;
	int equal = 0;

	while (i < strlen(lhs) && i < strlen(rhs) && equal == 0) {
		equal = lhs[i] - rhs[i];
		++i;
	}

	if (equal == 0) {
		equal = strlen(lhs) - strlen(rhs);
	}

	return equal;
}


int main() {
	char str[] = "asdf"; // \0 so-called nullterminator character at the end
	// printf("%d\n", sizeof(str) / sizeof(char));
	
	char str2[5];
	for (int i = 0; i < 5; ++i) {
		str2[i] = 'a';
	}
	str2[4] = '\0';

	printf("%d, %d\n", (unsigned)strlen(str2), strlen2(str2));

	// copy
	char target[10];
	// strcpy(target, str2);
	// printf("copied string: %s\n", target);
	
	for (int i = 0; i < 10; ++i) {
		target[i] = '*';
	}

	strcpy2(target, str2);
	printf("copied string with strcpy2: %s\n", target);


	strcpy3(target, "something");
	printf("copied with strcpy3: %s\n", target);

	char str3[] = "sas";
	printf("%s ", str3);
	reverse(str3);
	printf(", reversed: %s\n", str3);

	printf("equality check: %d\n", strcmp2("y", "asdf"));


	// read from stdin
	char name[50];
	scanf("%s", name);

	printf("Hello %s\n", name);

	int a, b;
	printf("Add two numbers separated by space: ");
	scanf("%d %d", &a, &b);
	printf("The sum of these numbers is: %d\n", a+b);


	return 0;
}
