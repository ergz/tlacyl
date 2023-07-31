/*
an ordered array is just a regular array except all elements must be in order,
so there a few things to note:

1. inserting must respect order
2. removing must respect order
3. serching can be made faster with binary search
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct FixedOrderedArray {
    int capacity;
    int index;  // index next to insert at, arr[index] should be empty
    int data[];
} FixedOrderedArray;

FixedOrderedArray *new_fixed_ordered_array(int capacity) {
    FixedOrderedArray *arr = malloc(sizeof(FixedOrderedArray) + (sizeof(int) * capacity));
    arr->capacity = capacity;
    arr->index = 0;

    return (arr);
}

void fixed_ordered_array_insert(FixedOrderedArray *arr, int val) {
    if (arr->capacity == arr->index) {
        fprintf(stderr, "ERROR: array is at capacity, cannot append value\n");
        exit(1);
    }

    if (arr->index == 0) {
        arr->data[0] = val;
        arr->index++;
    } else if (val >= arr->data[arr->index - 1]) {
        arr->data[arr->index] = val;
        arr->index++;
    } else if (val <= arr->data[0]) {           // its smallest to add to start
        for (int i = arr->index; i > 0; i--) {  // shift everything to the right
            arr->data[i] = arr->data[i - 1];
        }
        arr->data[0] = val;
        arr->index++;
    } else {  // look for where it belongs
        for (int i = 0; i < arr->index; i++) {
            if (arr->data[i] > val) {  // we must shift everything to the right up to this index
                for (int j = arr->index; j > i; j--) {
                    arr->data[j] = arr->data[j - 1];
                }
                arr->data[i] = val;
                arr->index++;
                break;
            }
        }
    }
}

bool search_fixed_ordered_array(FixedOrderedArray *arr, int val) {
    if (arr->index == 0) {
        return (false);
    }

    if (val < arr->data[0]) {
        return (false);
    }

    if (val > arr->data[arr->index - 1]) {
        return (false);
    }

    for (int i = 0; i < arr->index; i++) {
        if (val == arr->data[i]) {
            return (true);
        } else if (arr->data[i] > val) {
            return (false);
        }
    }
    return (false);
}

void print_array_list(FixedOrderedArray *arr) {
    printf("[");
    for (int i = 0; i < arr->index; i++) {
        printf(" %d ", arr->data[i]);
    }
    printf("]\t<capacity: %d; index: %d>\n", arr->capacity, arr->index);
}

int main() {
    FixedOrderedArray *arr = new_fixed_ordered_array(5);

    fixed_ordered_array_insert(arr, 10);
    print_array_list(arr);
    fixed_ordered_array_insert(arr, 9);
    print_array_list(arr);
    fixed_ordered_array_insert(arr, 13);
    print_array_list(arr);
    fixed_ordered_array_insert(arr, 11);
    print_array_list(arr);
    fixed_ordered_array_insert(arr, 9);
    print_array_list(arr);

    bool result = search_fixed_ordered_array(arr, 11);
    printf("the result is %d\n", result);
}
