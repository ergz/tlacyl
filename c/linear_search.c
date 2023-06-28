#include <stdio.h>
#include <stdbool.h>

bool linear_search(int *a, int len, int needle) {
	for (int i = 0; i < len; i++) {
		if (a[i] == needle) {
			return true;
		}
	}

	return false;
}

int main(int argc, char *argv[]) {
	int arr[5] = {1, 2, 3, 4, 5};
	int n = 5;
	printf("the value %d is in the array: %d", n, linear_search(arr, 5, n));
	return(0);
}
