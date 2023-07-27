#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct i32_ArrayList {
    int     capacity;  // capacity of the array
    int     index;     // the current location the list that is to be written to
    int32_t data[];    // the data
} i32_ArrayList;

i32_ArrayList *new_arraylist(int cap) {
    i32_ArrayList *arr = malloc(sizeof(i32_ArrayList) + cap * sizeof(int));

    if (arr == NULL) {
        printf("ERROR: there was an error attemping to allocate memory for i32_ArrayList\n");
        exit(1);
    }

    arr->capacity = cap;
    arr->index = 0;

    return arr;
}

// add to end of the array
void array_append(i32_ArrayList *s, int v) {
    if (s->index == s->capacity) {
        printf("you attempted to insert %d, but array is at capacity cannot add mode values\n", v);
    } else {
        s->data[s->index] = v;
        s->index++;
    }
}

// takes the address of a pointer
i32_ArrayList *resize_arraylist(i32_ArrayList *arr) {
    int new_cap = arr->capacity * 2;

    i32_ArrayList *new_arr = (i32_ArrayList *)realloc(arr, (sizeof(int) * new_cap) + sizeof(i32_ArrayList));

    if (new_arr == NULL) {
        fprintf(stderr, "ERROR: unable to resize array\n");
        exit(1);
    }

    new_arr->capacity = new_cap;
    return (new_arr);
}

void array_append2(i32_ArrayList **arr_ptr, int v) {
    i32_ArrayList *arr = *arr_ptr;
    if (arr->index == arr->capacity) {
        i32_ArrayList *new_arr = resize_arraylist(arr);
        *arr_ptr = new_arr;
        array_append(*arr_ptr, v);

    } else {
        array_append(arr, v);
    }
}

// create an array list and fill in with values from array
i32_ArrayList *new_arraylist_from_array(int cap, int *arr) {
    i32_ArrayList *out = new_arraylist(cap);
    for (int i = 0; i < cap; i++) {
        array_append(out, arr[i]);
    }

    return (out);
}

// insert value at index
// the strategy here is to start from the last element in the array and shift it to the right
// gotta be careful and check that the index + 1 <= capacity otherwise we are in trouble
void array_insert_at(i32_ArrayList *arr, int at_index, int32_t value) {
    if (at_index == arr->index) {
        array_append(arr, value);
    }

    if (at_index + 1 > arr->capacity) {
        printf("ERROR: this insert is not possible since the shift required would be over the capacity of the array\n");
        printf("You requested insert at %d but array capacity is set to %d\n", at_index, arr->capacity);
    }

    for (int i = arr->index; i >= at_index; i--) {
        arr->data[i + 1] = arr->data[i];
    }
    arr->data[at_index] = value;
}

int32_t array_get_at(i32_ArrayList *arr, int index) {
    return (arr->data[index]);
}

int32_t pop_from_array(i32_ArrayList *s) {
    if (s->index == 0) {
        printf("there is nothing to remove!\n");
        return (-99);
    } else {
        int32_t val = s->data[s->index - 1];
        s->index--;

        return (val);
    }
}

void print_array_list(i32_ArrayList *arr) {
    printf("[");
    for (int i = 0; i < arr->index; i++) {
        printf(" %d ", arr->data[i]);
    }
    printf("]\t<capacity: %d; index: %d>\n", arr->capacity, arr->index);
}

int main() {
    i32_ArrayList *a = new_arraylist(5);
    int            arr_values[5] = {1, 2, 3, 4, 5};
    i32_ArrayList *b = new_arraylist_from_array(5, arr_values);
    print_array_list(b);

    // these should all work just fine
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

    // this one will error
    array_append(a, 100);

    // so we remove one and then add
    pop_from_array(a);
    print_array_list(a);
    array_append(a, 100);
    print_array_list(a);

    // now we test inserting different index
    array_insert_at(a, 3, 55);
    print_array_list(a);
    array_insert_at(a, 4, 555);
    print_array_list(a);

    // what happens if try to insert at the last element
    // this first implementation of the araylist will just overwrite this value
    array_insert_at(a, 4, 100);
    print_array_list(a);

    // what if insert at 3 in this first version?
    // this will shift the current 3 to 4, but this causes the 100 to be removed
    array_insert_at(a, 3, 123);
    print_array_list(a);
    array_append2(&a, 5000);
    print_array_list(a);

    printf("--------------------------------\n");
    print_array_list(b);
    array_append2(&b, 100);
    print_array_list(b);
    // array_append(a, 14);
    // print_array_list(a);
    // pop_from_array(a);
    // print_array_list(a);
    // array_insert_at(a, 5, 90000);
    // print_array_list(a);
    // array_insert_at(a, 3, 1000);
    // array_insert_at(a, 4, 1000);
    // array_insert_at(a, 5, 10001);
    // print_array_list(a);
}
