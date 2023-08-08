#include <stdio.h>

void insertion_sort(int arr[], int len) {
    int temp;
    int j;
    for (int i = 1; i < len; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0) {
            if (temp < arr[j]) {
                arr[j + 1] = arr[j];
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = temp;
    }
}

void print_array(int arr[], int len) {
    printf("[ ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main() {
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 1, 2};
    insertion_sort(arr, 10);
    print_array(arr, 10);
}