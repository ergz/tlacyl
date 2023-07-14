/*
implementation of binary tree, in the course he just jumps into
search algorithms but uses built in javascript data structures
to jump a bunch of steps, here I write everything from scratch
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int          value;
    struct Node* prev;
} Node;

typedef struct Stack {
    int   len;
    Node* head;
} Stack;

Stack* new_stack() {
    Stack* s = malloc(sizeof(Stack));
    s->head = NULL;
    s->head = 0;
    return (s);
}

Node* new_node(int value) {
    Node* n = malloc(sizeof(Node));
    n->prev = NULL;
    n->value = value;

    return (n);
}

void push(Stack* stack, Node* node) {
    if (stack->len == 0) {
        stack->head = node;
        stack->len++;
    } else {
        node->prev = stack->head;
        stack->head = node;
        stack->len++;
    }
}

int pop(Stack* stack) {
    if (stack->len > 0) {
        Node* node = stack->head;
        int   node_val = node->value;
        stack->head = node->prev;
        free(node);
        return (node_val);
    }
}

typedef struct IntBinaryNode {
    int                   value;
    struct IntBinaryNode* left;
    struct IntBinaryNode* right;
} IntBinaryNode;

IntBinaryNode* new_int_binary_node(int value) {
    IntBinaryNode* n = malloc(sizeof(IntBinaryNode));
    n->value = value;

    return (n);
}

typedef struct BinaryTree {
    IntBinaryNode* root;
} BinaryTree;

BinaryTree* new_binary_tree(IntBinaryNode* n) {
    BinaryTree* b = malloc(sizeof(BinaryTree));
    b->root = n;

    return (b);
}

void add_child_node(IntBinaryNode* parent, IntBinaryNode* child, char position) {
    if (position != 'l' && position != 'r') {
        printf("ERROR: position must be either (l)eft or (r)ight\n");
        exit(1);
    }

    if (position == 'l') {
        if (parent->left != NULL) {
            printf("ERROR: left position of parent is already occupied");
            exit(1);
        } else {
            parent->left = child;
        }
    } else if (position == 'r') {
        if (parent->right != NULL) {
            printf("ERROR: right position of parent is already occupied");
            exit(1);
        } else {
            parent->right = child;
        }
    }
}

// prints the bottom row of a tree
void print_binary_tree(IntBinaryNode* node) {
    if (node->left == NULL && node->right == NULL) {
        printf("<%d>\n", node->value);
    } else {
        print_binary_tree(node->left);
        print_binary_tree(node->right);
    }
}

void walk_tree(IntBinaryNode* current_node, Stack* stack) {
    if (current_node->left == NULL && current_node->right == NULL) {
        printf("looking at value: %d\n", current_node->value);
        push(stack, new_node(current_node->value));
    } else {
        printf("looking at value: %d\n", current_node->value);
        push(stack, new_node(current_node->value));

        walk_tree(current_node->left, stack);
        walk_tree(current_node->right, stack);
    }
}

void print_stack(Stack* stack) {
    if (stack->len == 0) {
        printf("empty stack\n");
    } else {
        printf("[ ");
        while (stack->len > 0) {
            int res = pop(stack);
            printf("%d ", res);
        }
        printf("]\n");
    }
}

int main() {
    /* lets create the following tree
                12
            4       6
          10 11   44 77

     */
    IntBinaryNode* root_node = new_int_binary_node(12);
    BinaryTree*    tree = new_binary_tree(root_node);

    add_child_node(root_node, new_int_binary_node(4), 'l');
    add_child_node(root_node, new_int_binary_node(6), 'r');

    add_child_node(root_node->left, new_int_binary_node(10), 'l');
    add_child_node(root_node->left, new_int_binary_node(11), 'r');
    add_child_node(root_node->right, new_int_binary_node(44), 'l');
    add_child_node(root_node->right, new_int_binary_node(77), 'r');

    Stack* stack = new_stack();
    walk_tree(root_node, stack);

    printf("the len of the stack is %d\n", stack->len);
    print_stack(stack);
    free(stack);

    return (0);
}