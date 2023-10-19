#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>

typedef struct Node Node;
struct Node {
    Node* parent;
    Node* left_ch;
    Node* right_ch;

    void* data;
};

typedef struct Binary_Tree {
    Node* root;
    size_t size;
} Binary_Tree;

Node* new_node(Node*, Node*, Node*, void*);
Binary_Tree* new_tree(Node*);

void push_node(Binary_Tree*, void*);
void remove_node(Binary_Tree*, void*);

#endif
