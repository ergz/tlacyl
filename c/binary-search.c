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

typedef struct BinaryNode {
    int                value;
    struct BinaryNode* left;
    struct BinaryNode* right;
} BinaryNode;

BinaryNode* new_binary_node(int value) {
    BinaryNode* node = malloc(sizeof(BinaryNode));
    node->value = value;

    return (node);
}

int main() {
    return (0);
}