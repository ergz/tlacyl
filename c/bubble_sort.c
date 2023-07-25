#include <stdio.h>

void bubble_sort(int arr[], int len) {
    int total_iterations = 0;
    int temp;
    int total_swaps = 1;
    for (int i = 0; i < len; i++) {
        total_iterations++;
        if (total_swaps == 0) {
            break;
        }
        total_swaps = 0;
        for (int j = 0; j < len - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                total_swaps++;
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("total iterations: %d\n", total_iterations);
}

void print_array(int* arr, int len) {
    printf("[ ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main() {
    int arr[5] = {2, 1, 3, 4, 5};
    printf("before the sort:\n");
    print_array(arr, 5);
    bubble_sort(arr, 5);
    printf("after the sort:\n");
    print_array(arr, 5);
}