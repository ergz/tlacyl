#include <stdbool.h>
#include <stdio.h>

bool binary_search(int *arr, int len, int val) {
    int lo_bound = 0;
    int hi_bound = len - 1;

    int mid_index;
    int mid_val;

    int counter = 1;

    while (lo_bound <= hi_bound) {
        mid_index = (hi_bound + lo_bound) / 2;

        mid_val = arr[mid_index];

        if (mid_val == val) {
            return (true);
        }

        if (val < mid_val) {
            hi_bound = mid_index - 1;
        } else {
            lo_bound = mid_index + 1;
        }

        counter++;
    }
    printf("total iterations: %d\n", counter);
    return (false);
}

int main() {
    int  arr[8] = {1, 3, 4, 5, 6, 7, 8, 10};
    bool result = binary_search(arr, 8, 11);
    printf("the result is %s\n", result ? "true" : "false");
}