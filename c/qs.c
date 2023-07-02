#include <stdio.h>

// partition takes an array and a low and hi values and partitions the array
// by rearrating and placing everything smaller then the pivot point to the left
// of it and everything greater than it on the right
int partition(int arr[], int lo, int hi) {
    int pivot_value = arr[hi];
    int idx = -1;  // this will keep track of current location of values less then the pivot

    for (int i = 0; i < hi; i++) {
        if (arr[i] <= pivot_value) {
            idx++;

            // if less than the pivot then swap the ith value with the current idx
            int tmp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = tmp;
        }
    }

    // after the iteration we still need to reposition our pivot_value to the last
    // position that idx was after the for loop ends, this will mean that everything
    // to left of idx will be less than the pivot point
    idx++;
    arr[hi] = arr[idx];
    arr[idx] = pivot_value;

    return (idx);
}

void quick_sort(int arr[], int lo, int hi) {
    if (lo < hi) {
        int current_pivot = partition(arr, lo, hi);
        quick_sort(arr, lo, current_pivot - 1);
        quick_sort(arr, current_pivot + 1, hi);
    }
}

int main() {
    int array_len = 5;
    int arr[5] = {5, 4, 3, 2, 1};
    quick_sort(arr, 0, array_len - 1);

    printf("[ ");
    for (int i = 0; i < array_len; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}