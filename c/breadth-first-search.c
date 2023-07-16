#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int              value;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

typedef struct Tree {
    TreeNode* root;
} Tree;

/*  Set up data structures to be able to support the breadth first search of a tree */
typedef struct QNode {
    TreeNode*     tnode;  // this is the value of the QNode
    struct QNode* next;
} QNode;

typedef struct Q {
    QNode* head;
    QNode* tail;
    int    length;
} Q;

TreeNode* new_tree_node(int value) {
    TreeNode* node = malloc(sizeof(TreeNode));
    node->left = NULL;
    node->right = NULL;
    node->value = value;

    return (node);
}

QNode* new_qnode(TreeNode* tnode) {
    QNode* node = malloc(sizeof(QNode));
    node->next = NULL;
    node->tnode = tnode;

    return (node);
}

Tree* new_tree(TreeNode* root) {
    Tree* tree = malloc(sizeof(Tree));
    tree->root = root;
    return (tree);
}

Q* new_Q() {
    Q* q = malloc(sizeof(Q));
    q->head = NULL;
    q->tail = NULL;
    q->length = 0;

    return (q);
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

// always add at tail
void q_add_node(Q* q, QNode* node) {
    if (q->length == 0) {
        q->head = node;
        q->tail = node;
        q->length++;
    } else {
        q->tail->next = node;
        q->tail = node;
        q->length++;
    }
}

// always remove from head
TreeNode* q_remove_node(Q* q) {
    QNode*    n = q->head;
    TreeNode* tnode_at_head = n->tnode;
    q->head = n->next;
    q->length--;
    free(n);
    return (tnode_at_head);
}

/*
                10
            5        7
        12    8    88    14

 */

bool bf_search(Tree tree, int value) {
    // start by adding th eroot of tree to the q
    Q*     search_path = new_Q();
    QNode* n = new_qnode(tree.root);
    q_add_node(search_path, n);
    TreeNode* current_value;
    while (search_path->length > 0) {
        current_value = q_remove_node(search_path);

        if (current_value->value == value) {
            free(search_path);
            return (true);
        }

        if (current_value->left != NULL) {
            q_add_node(search_path, new_qnode(current_value->left));
        }
        if (current_value->right != NULL) {
            q_add_node(search_path, new_qnode(current_value->right));
        }
    }
    free(search_path);
    return (false);
}

int main() {
    TreeNode* root = new_tree_node(10);
    Tree*     tree = new_tree(root);

    add_child_left(root, new_tree_node(5));
    add_child_right(root, new_tree_node(7));

    add_child_left(root->left, new_tree_node(12));
    add_child_right(root->left, new_tree_node(8));

    add_child_left(root->right, new_tree_node(88));
    add_child_right(root->right, new_tree_node(14));

    bool answer;
    answer = bf_search(*tree, 90);
    printf("the answer is %d\n", answer);
}
