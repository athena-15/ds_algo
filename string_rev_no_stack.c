#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b) {
	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void reverse(char *str) {
	int i = 0;
	int len = strlen(str);

	for (i = 0; i < len / 2; i++) {
		swap(&str[i], &str[len - i - 1]);
	}
}

void main() {
	char str[] = "Hello";

	reverse(str);

	printf("\n %s", str);
}
