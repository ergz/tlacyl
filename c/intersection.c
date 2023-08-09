#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA 50

typedef struct ArrayList {
    int cap;
    int index;
    int data[];
} ArrayList;

ArrayList *new_array_list(int cap) {
    ArrayList *arr = malloc(sizeof(ArrayList) + cap * sizeof(int));

    if (arr == NULL) {
        fprintf(stderr, "ERROR: cannot allocate mem for arraylist\n");
    }
    arr->cap = cap;
    arr->index = 0;

    return (arr);
}

void push(ArrayList *arr, int val) {
    if (arr->index == arr->cap) {
        fprintf(stderr, "ERROR: cannot append to array at capacity");
        exit(1);
    }

    arr->data[arr->index] = val;
    arr->index++;
}

void pop(ArrayList *arr) {
    if (arr->index == 0) {
        fprintf(stderr, "ERROR: canoot pop from empty array");
        exit(1);
    }

    arr->index--;
}

/* for now we only return the indices on the left that that are in the right */
ArrayList *intersection(int left[], int right[], int left_len, int right_len) {
    ArrayList *arr = new_array_list(left_len);

    for (int i = 0; i < left_len; i++) {
        for (int j = 0; j < right_len; j++) {
            if (left[i] == right[j]) {
                push(arr, left[i]);
                break;
            }
        }
    }

    return (arr);
}

int main() {
    int a[5] = {1, 2, 3, 4, 8};
    int b[5] = {4, 5, 6, 7, 8};

    ArrayList *arr = intersection(a, b, 5, 5);
    for (int i = 0; i < 2; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
    return (0);
}