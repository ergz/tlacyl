#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int len) {
    int lo_index;
    for (int i = 0; i < len; i++) {          // keep track of pass
        lo_index = i;                        // low index always starts as the pass iteration
        for (int j = i + 1; j < len; j++) {  // keep track of array comparisons
            if (arr[j] < arr[i]) {
                lo_index = j;
            }
        }  // after done with this loop we swap the value at lo_index to the current pass index

        swap(&arr[i], &arr[lo_index]);
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
    int arr[5] = {5, 4, 3, 2, 1};
    selection_sort(arr, 5);
    print_array(arr, 5);
}