#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayList {
    int capacity;
    int index;
    int data[];
} ArrayList;

ArrayList* new_arraylist(int cap) {
    ArrayList* arr = malloc(sizeof(ArrayList) + cap * sizeof(int));
    arr->capacity = cap;
    arr->index = 0;
    for (int i = 0; i < cap; i++) {
        arr->data[i] = 0;
    }

    return arr;
}

void push_to_array(ArrayList* s, int v) {
    if (s->index == s->capacity) {
        printf("you attempted to insert %d, but array is at capacity cannot add mode values\n", v);
    } else {
        s->data[s->index] = v;
        s->index++;
    }
}

void pop_from_array(ArrayList* s) {
    if (s->index == 0) {
        printf("there is nothing to remove!\n");
    } else {
        s->index--;
    }
}

void grow_array_list(ArrayList* s, int amount) {
}

void print_array_list(ArrayList* arr) {
    printf("[");
    for (int i = 0; i < arr->index; i++) {
        printf(" %d ", arr->data[i]);
    }
    printf("]\n");
}

int main() {
    ArrayList* a = new_arraylist(5);
    push_to_array(a, 10);
    push_to_array(a, 11);
    push_to_array(a, 12);
    push_to_array(a, 12);
    push_to_array(a, 12);
    push_to_array(a, 12);
    push_to_array(a, 12);
    pop_from_array(a);
    push_to_array(a, 155);
    print_array_list(a);
}