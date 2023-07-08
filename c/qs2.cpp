#include <stdio.h>

/* a rewrite to make sure I can do this without reading */

/*
partition

Modifies array by moving all values less then a pivot point
to the left of it and all value greater to the right. Returns
the index of the pivot at the end of the process.

@param int arr[] array to partition
@param int lo low value to start iteration on
@param int hi high value to end iteration on
 */
int partition(int arr[], int lo, int hi) {
    int pindex = lo - 1;        // where pivot will end up
    int pivot_value = arr[hi];  // can be different

    for (int i = lo; i < hi; i++) {
        if (arr[i] <= pivot_value) {
            pindex++;
            int temp = arr[i];
            arr[i] = arr[pindex];
            arr[pindex] = temp;
        }
    }

    // after iterating through array, we place pivot in correct
    // position
    pindex++;
    arr[hi] = arr[pindex];
    arr[pindex] = pivot_value;

    return (pindex);
}

/*
quick_sort

@param int arr[] array to be sorted
@param int lo starting point for iteration
@param int hi ending point for itereation
 */
void quick_sort(int arr[], int lo, int hi) {
    if (lo < hi) {  // base case is lo == hi
        int pivot_index = partition(arr, lo, hi);

        quick_sort(arr, lo, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, hi);
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
    printf("before ");
    print_array(arr, 5);
    quick_sort(arr, 0, 4);
    printf("after ");
    print_array(arr, 5);
}