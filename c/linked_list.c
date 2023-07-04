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
void append(LinkedList* list, Node* n) {
    if (list->length == 0) {
        list->head = n;
        list->tail = n;
        list->length++;
    } else {
        list->tail->next = n;
        n->prev = list->tail;
        list->tail = n;
        list->length++;
    }
}

// prepend - insert a node at the front of the linked list
void preppend(LinkedList* list, Node* node) {
    if (list->length == 0) {
        list->head = node;
        list->tail = node;
        list->length++;
    } else {
        list->head->prev = node;
        node->next = list->head;
        // prev is already initialized to NULL so no need to add that here
        list->head = node;
        list->length++;
    }
}

// insert at - insert a node at a given index
void insert_at(LinkedList* list, Node* node, int index) {
    if (index == 0) {
        preppend(list, node);
    } else if (index == list->length) {
        append(list, node);
    } else if (index > list->length || index < 0) {
        printf("ERROR: cannot add to list at index position %d, this is beyond the current index\n", index);
    } else {
        Node* current_node_at_index = list->head;
        // get to the ith node
        for (int i = 0; i < index; i++) {
            current_node_at_index = current_node_at_index->next;
        }

        node->prev = current_node_at_index->prev;
        node->next = current_node_at_index;
        current_node_at_index->prev->next = node;
        current_node_at_index->prev = node;
        list->length++;
    }
}

int get_length(LinkedList* list) {
    return (list->length);
}

void destroy_list(LinkedList* list) {
    // if any nodes are in list destroy them first
    if (list->length > 0) {
        Node* current_node = list->head;
        while (current_node != NULL) {
            Node* next_node = current_node->next;
            free(current_node);
            current_node = next_node;
        }
    }

    // then destroy the list struct itself
    free(list);
}

void print_list(LinkedList* list) {
    Node* curr = list->head;
    printf("[ ");
    while (curr != NULL) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    printf("] <length: %d>\n", get_length(list));
}

int main() {
    LinkedList* list = new_linked_list();
    Node*       a = new_node(10);
    Node*       b = new_node(11);
    preppend(list, a);
    preppend(list, b);
    preppend(list, new_node(12));
    preppend(list, new_node(13));
    preppend(list, new_node(14));
    preppend(list, new_node(15));

    append(list, new_node(100));
    append(list, new_node(200));

    print_list(list);
    insert_at(list, new_node(-1), 0);
    insert_at(list, new_node(-1), 4);
    print_list(list);

    destroy_list(list);

    return (0);
}