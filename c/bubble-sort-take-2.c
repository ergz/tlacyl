#include <stdio.h>

/*
in bubble sort we iterate through the array each time we encounter adjacent elements
out of order, we swap them. We continue this iteration until we have reached
 */

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int arr[], int len) {
    int swap_count = 1;
    int temp;
    int end_index = len - 1;

    while (swap_count > 0) {
        swap_count = 0;
        for (int i = 0; i < end_index; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swap_count++;
            }
        }
        end_index--;
    }
}

void print_array(int arr[], int len) {
    printf("[ ");
    for (int i = 0; i < len; i++) {
        printf(" %d", arr[i]);
    }
    printf(" ]\n");
}

int main() {
    int input[5] = {5, 4, 3, 2, 1};
    bubble_sort(input, 5);
    print_array(input, 5);
}