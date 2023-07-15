/*
implementation of binary tree, in the course he just jumps into
search algorithms but uses built in javascript data structures
to jump a bunch of steps, here I write everything from scratch
 */

/*
next challenge to is write a function to read in a json file and
parse it as a tree???
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
    s->len = 0;
    return (s);
}

Node* new_node(int value) {
    Node* n = malloc(sizeof(Node));
    n->prev = NULL;
    n->value = value;

    return (n);
}

void json_file_to_tree(char* filepath) {
    // TODO!!!!
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
        stack->len--;
        free(node);
        return (node_val);
    }

    return (-9999);
}

typedef struct IntBinaryNode {
    int                   value;
    struct IntBinaryNode* left;
    struct IntBinaryNode* right;
} IntBinaryNode;

IntBinaryNode* new_int_binary_node(int value) {
    IntBinaryNode* n = malloc(sizeof(IntBinaryNode));
    n->left = NULL;
    n->right = NULL;
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

void walk_tree_pre_order(IntBinaryNode* current_node, Stack* stack) {
    if (current_node->left == NULL && current_node->right == NULL) {
        push(stack, new_node(current_node->value));
    } else {
        push(stack, new_node(current_node->value));
        walk_tree_pre_order(current_node->left, stack);
        walk_tree_pre_order(current_node->right, stack);
    }
}

void walk_tree_post_order(IntBinaryNode* current_node, Stack* stack) {
    if (current_node->left == NULL && current_node->right == NULL) {
        push(stack, new_node(current_node->value));
    } else {
        walk_tree_pre_order(current_node->left, stack);
        walk_tree_pre_order(current_node->right, stack);
        push(stack, new_node(current_node->value));
    }
}

void walk_tree_in_order(IntBinaryNode* current_node, Stack* stack) {
    if (current_node->left == NULL && current_node->right == NULL) {
        push(stack, new_node(current_node->value));
    } else {
        walk_tree_pre_order(current_node->left, stack);
        push(stack, new_node(current_node->value));
        walk_tree_pre_order(current_node->right, stack);
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

void print_stack_v2(Stack* stack) {
    if (stack->len == 0) {
        printf("ERROR: empty stack\n");
    } else {
        printf("[ ");
        int   counter = 0;
        Node* curr = stack->head;
        while (counter < stack->len) {
            printf("%d ", curr->value);
            curr = curr->prev;
            counter++;
        }
        printf(" ]\n");
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
    Stack* post_stack = new_stack();
    Stack* in_order_stack = new_stack();
    walk_tree_pre_order(root_node, stack);
    walk_tree_post_order(root_node, post_stack);
    walk_tree_in_order(root_node, in_order_stack);

    printf("pre order:  ", stack->len);
    print_stack_v2(stack);
    printf("in order:   ", stack->len);
    print_stack_v2(post_stack);
    printf("post order: ", stack->len);
    print_stack_v2(in_order_stack);
    free(stack);
    free(post_stack);
    free(in_order_stack);

    return (0);
}
