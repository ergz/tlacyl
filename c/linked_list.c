#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int          value;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct LinkedList {
    int   length;
    Node* head;
    Node* tail;
} LinkedList;

LinkedList* new_linked_list() {
    LinkedList* ll = malloc(sizeof(LinkedList));
    ll->length = 0;

    return (ll);
}

Node* new_node(int value) {
    Node* n = malloc(sizeof(Node));
    n->value = value;
    n->next = NULL;
    n->prev = NULL;
    return (n);
}

// append - insert a node at the end of the linked list

// prepend - insert a node at the front of the linked list
void preppend(LinkedList* list, Node* node) {
    if (list->length == 0) {
        list->head = node;
        list->tail = node;
        list->length++;
    } else {
        list->head->prev = node;
        node->next = list->head;
        list->head = node;
    }
}

void print_list(LinkedList* list) {
    Node* curr = list->head;
    printf("[ ");
    while (curr != NULL) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("]\n");
}

int get_size_list(LinkedList* list) {
    return 0;
}

// insert at - insert a node at a given index

int main() {
    LinkedList* list = new_linked_list();
    Node*       a = new_node(10);
    Node*       b = new_node(11);
    append(list, a);
    append(list, b);
    append(list, new_node(12));
    append(list, new_node(13));
    append(list, new_node(14));
    append(list, new_node(15));

    print_list(list);
    return (0);
}