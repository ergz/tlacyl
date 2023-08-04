#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int len) {
    int curr_low;
    int low_index = 0;
    int pass_index = 0;

    for (int i = 0; i < len; i++) {
        low_index = i;
        for (int j = i + 1; j < len; j++) {
            if (arr[i] > arr[j]) {  // if we encounter a new low
                low_index = j;
            }
        }
        swap(&arr[i], &arr[low_index]);
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
    int arr[6] = {5, 3, 4, 2, 1, 7};
    selection_sort(arr, 6);
    print_array(arr, 6);
}