#include <stdio.h>

#include "binary_tree.h"

Node* new_node(Node* p_parent, Node* p_left_ch, Node* p_right_ch, void* p_data) {
    Node* new_n;
    new_n->parent = p_parent;
    new_n->left_ch = p_left_ch;
    new_n->right_ch = p_right_ch;
    new_n->data = p_data;
    return new_n;
}

Binary_Tree* new_tree(Node* p_root) {
    Binary_Tree* new_t;
    if (p_root == NULL) {
        new_t->root = NULL;
        new_t->size = 0;
        return new_t;
    }

    new_t->root = p_root;
    new_t->size = 1;
    return new_t;
}

