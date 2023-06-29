#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

typedef struct Node {
    int          value;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int   length;
} Queue;

// void enqueue(Queue q) {}

// void enqueue(Queue q) {}

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
