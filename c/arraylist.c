#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct i32_ArrayList {
    int     capacity;  // capacity of the array
    int     index;     // the current location the list that is to be written to
    int32_t data[];    // the data
} i32_ArrayList;

i32_ArrayList* new_arraylist(int cap) {
    i32_ArrayList* arr = malloc(sizeof(i32_ArrayList) + cap * sizeof(int));
    arr->capacity = cap;
    arr->index = 0;

    return arr;
}

// add to end of the array
void array_append(i32_ArrayList* s, int v) {
    if (s->index == s->capacity) {
        printf("you attempted to insert %d, but array is at capacity cannot add mode values\n", v);
    } else {
        s->data[s->index] = v;
        s->index++;
    }
}

// insert value at index
void array_insert_at(i32_ArrayList* arr, int index, int32_t value) {
    for (int i = index; i > arr->index; i--) {
        arr->data[i] = arr->data[i - 1];
    }
}

int32_t array_get_at(i32_ArrayList* arr, int index) {
    return (arr->data[index]);
}

int32_t pop_from_array(i32_ArrayList* s) {
    if (s->index == 0) {
        printf("there is nothing to remove!\n");
        return (-99);
    } else {
        int32_t val = s->data[s->index - 1];
        s->index--;

        return (val);
    }
}

void grow_array_list(i32_ArrayList* s, int amount) {
}

void print_array_list(i32_ArrayList* arr) {
    printf("[");
    for (int i = 0; i < arr->index; i++) {
        printf(" %d ", arr->data[i]);
    }
    printf("]\n");
}

int main() {
    i32_ArrayList* a = new_arraylist(5);
    array_append(a, 10);
    print_array_list(a);
    array_append(a, 11);
    print_array_list(a);
    array_append(a, 12);
    print_array_list(a);
    array_append(a, 13);
    print_array_list(a);
    array_append(a, 14);
    print_array_list(a);
    pop_from_array(a);
    print_array_list(a);
    array_append(a, 15);
    print_array_list(a);
    array_insert_at(a, 3, 55);
    print_array_list(a);
    printf("%d\n", array_get_at(a, 3));
}