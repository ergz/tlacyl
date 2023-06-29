#include <stdio.h>

// asume the array is sorted of course
void bubble_sort(int arr[], int len) {
    int temp;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[5] = {1, 3, 2, 4, 5};
    bubble_sort(arr, 5);

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}