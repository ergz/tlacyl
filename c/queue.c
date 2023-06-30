#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

typedef struct Node {
    int          value;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
    int   length;
} Queue;

typedef struct ArrayQueue {
    Node* head;
    Node* tail;
    int   length;
    Node* data[MAX_LEN];
} ArrayQueue;

ArrayQueue* new_array_queue() {
    ArrayQueue* a_q = malloc(sizeof(ArrayQueue));
    a_q->head = NULL;
    a_q->tail = NULL;
    for (int i = 0; i < MAX_LEN; i++) {
        a_q->data[i] = NULL;
    }
    a_q->length = 0;

    return (a_q);
}

void arr_enqueue(ArrayQueue* a, Node* n) {
    if (a->length == 0) {
        a->head = n;
        a->tail = n;
        a->data[a->length] = n;
        a->length++;
    } else {
        a->tail = n;
        a->data[a->length] = n;
        a->length++;
    }
}

// not a very good idea, this will require a O(n) walk through the array to
// shift everything to the left
bool arr_dequeue(ArrayQueue* a) {
    if (a->length == 0) {
        return false;
    } else {
    }
}

void enqueue(Queue* q, Node* n) {
    if (q->length == 0) {
        q->head = n;
        q->tail = n;
    } else {
        q->tail->next = n;
        q->tail = n;
    }
    q->length++;
}

bool dequeue(Queue* q) {
    if (q->length == 0) {
        return false;
    } else {
        q->head = q->head->next;
        return true;
    }
}

Queue* new_queue() {
    Queue* q = malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    q->length = 0;
    return q;
}

Node* new_node(int value) {
    Node* n = malloc(sizeof(Node));
    n->value = value;
    n->next = NULL;
    return n;
}

void free_node(Node* n) {
    if (n != NULL) {
        free(n);
    }
}

Node* peek(Queue* q) { return q->head; }

int main() {
    Queue* q = new_queue();
    Node*  p = new_node(10);
    Node*  r = new_node(11);
    // Node* n;
    enqueue(q, p);
    enqueue(q, r);
    Node* n = peek(q);
    printf("the value at the head node is: %d\n", n->value);

    dequeue(q);
    n = peek(q);
    printf("the value at the head node is: %d\n", n->value);

    return (0);
}
