#include <stdio.h>
#include <stdlib.h>

/*  Set up data structures to be able to support the breadth first search of a tree */
typedef struct QNode {
    int           value;
    struct QNode* next;
    struct QNode* prev;
} QNode;

typedef struct Q {
    QNode* head;
    QNode* tail;
} Q;

typedef struct TreeNode {
    int              value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct Tree {
    TreeNode* root;
} Tree;

TreeNode* new_tree_node(int value) {
    TreeNode* node = malloc(sizeof(TreeNode));
    node->left = NULL;
    node->right = NULL;
    node->value = value;

    return (node);
}

QNode* new_qnode(int value) {
    QNode* node = malloc(sizeof(QNode));
    node->next = NULL;
    node->prev = NULL;
    node->value = value;

    return (node);
}

Tree* new_tree(TreeNode* root) {
    Tree* tree = malloc(sizeof(Tree));
    tree->root = root;
    return (tree);
}

void add_child_left(TreeNode* parent, TreeNode* node) {
    if (parent->left != NULL) {
        printf("ERROR: left child is non-empty\n");
        exit(1);
    } else {
        parent->left = node;
    }
}

void add_child_right(TreeNode* parent, TreeNode* node) {
    if (parent->right != NULL) {
        printf("ERROR: right child is non-empty\n");
        exit(1);
    } else {
        parent->right = node;
    }
}

/*
                10
            5        7
        12    8    88    14

 */

int main() {
    TreeNode* root = new_tree_node(10);
    Tree*     tree = new_tree(root);

    add_child_left(root, new_tree_node(5));
    add_child_right(root, new_tree_node(7));

    add_child_left(root->left, new_tree_node(12));
    add_child_right(root->left, new_tree_node(8));

    add_child_left(root->right, new_tree_node(88));
    add_child_right(root->right, new_tree_node(14));
}