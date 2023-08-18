#include <stdio.h>

// the partition will weakly sort the array and return the index of
// the pivot
int partition(int arr[], int lo, int hi) {
    int pivot_value = arr[hi];
    int current_index = lo - 1;
    int temp;
    for (int i = lo; i < hi; i++) {
        if (arr[i] <= pivot_value) {
            current_index++;

            temp = arr[i];
            arr[i] = arr[current_index];
            arr[current_index] = temp;
        }
    }

    // once done with loop the current_index will hold
    // the location where we need to place the pivot_value
    current_index++;
    arr[hi] = arr[current_index];
    arr[current_index] = pivot_value;

    return (current_index);
}

void qs(int arr[], int lo, int hi) {
    if (lo < hi) {
        int current_pivot = partition(arr, lo, hi);
        qs(arr, lo, current_pivot - 1);
        qs(arr, current_pivot + 1, hi);
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
    int arr[5] = {0, 2, 5, 1, 6};
    print_array(arr, 5);
    qs(arr, 0, 4);
    print_array(arr, 5);

    return (0);
}