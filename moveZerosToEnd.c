#include <stdio.h>

void moveZeroesToEnd(int *arr, int len) {
	int nonzerocnt = 0;

	for (int i = 0; i < len; i++) {
		if (arr[i] != 0) {
			arr[nonzerocnt++] = arr[i];
		}
	}

	while (nonzerocnt < len)
		arr[nonzerocnt++] = 0;
}

void main() {
	int arr[] = {1, 2, 4, 6, 0, 3, 0};

	int size = sizeof(arr) / sizeof(*arr);

	moveZeroesToEnd(arr, size);

	for (int i = 0; i < size; i++) {
		printf("\n %d", arr[i]);
	}
}
