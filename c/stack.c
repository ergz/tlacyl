#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/*
how a stack grows

len = 0  ______
push: len = 1 [A]
push: len = 2 [A] <-- [B]             new elements point to the previous top
push: len = 3 [A] <-- [B] <-- [C]
pop:  len = 2 [A] <-- [B] <-/- [C] need to free C here and set new head of Stack to be B
pop:  len = 1 [A] <-/- [B]
pop:  len = 0 /[A]/


 */

typedef struct Node {
    int          value;
    struct Node* next;
} Node;

typedef struct Stack {
    int   length;
    Node* head;
} Stack;

Node* new_node(int value) {
    Node* n = malloc(sizeof(Node));
    n->value = value;
    n->next = NULL;
    return (n);
}

Stack* new_stack() {
    Stack* s = malloc(sizeof(Stack));
    s->length = 0;
    s->head = NULL;
    return (s);
}

bool pop(Stack* s) {
    if (s->length == 0) {
        return false;
    } else {
        Node* n = s->head;
        if (s->length == 1) {
            s->head = NULL;
        } else {
            s->head = n->next;
        }
        free(n);
        s->length--;
        return true;
    }
}

void delete_stack(Stack* s) {
    while (s->head != NULL) {
        pop(s);
    }
}

void push(Stack* s, Node* n) {
    if (s->length == 0) {
        s->head = n;
        s->length++;
    } else {
        // make the old head point to what will be the new head
        n->next = s->head;
        // make the head point to n now
        s->head = n;
        s->length++;
    }
}

int peek(Stack* s) {
    if (s->length == 0) {
        return -1;
    }

    return s->head->value;
}

int main() {
    Stack* s = new_stack();

    Node* a = new_node(10);
    Node* b = new_node(11);
    Node* c = new_node(12);
    Node* d = new_node(13);

    push(s, a);
    printf("the value at the top of the stack is: %d\n", peek(s));
    printf("the length of the stack is: %d\n", s->length);
    push(s, b);
    printf("the value at the top of the stack is: %d\n", peek(s));
    printf("the length of the stack is: %d\n", s->length);
    push(s, c);
    printf("the value at the top of the stack is: %d\n", peek(s));
    printf("the length of the stack is: %d\n", s->length);
    push(s, d);
    printf("the value at the top of the stack is: %d\n", peek(s));
    printf("the length of the stack is: %d\n", s->length);

    // bool res = pop(s);
    // printf("the value at the top of the stack is: %d\n", peek(s));
    // printf("the length of the stack is: %d\n", s->length);

    // res = pop(s);
    // printf("the value at the top of the stack is: %d\n", peek(s));
    // printf("the length of the stack is: %d\n", s->length);

    // res = pop(s);
    // printf("the value at the top of the stack is: %d\n", peek(s));
    // printf("the length of the stack is: %d\n", s->length);

    // res = pop(s);
    // printf("the value at the top of the stack is: %d\n", peek(s));
    // printf("the length of the stack is: %d\n", s->length);
    // res = pop(s);
    // printf("the value at the top of the stack is: %d\n", peek(s));
    // printf("the length of the stack is: %d\n", s->length);
    // res = pop(s);
    // printf("the value at the top of the stack is: %d\n", peek(s));
    // printf("the length of the stack is: %d\n", s->length);
    // res = pop(s);
    // printf("the value at the top of the stack is: %d\n", peek(s));
    // printf("the length of the stack is: %d\n", s->length);

    delete_stack(s);

    return (0);
}