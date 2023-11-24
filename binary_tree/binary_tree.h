#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>

typedef enum { INT, FLOAT, CHAR } DATA_TYPE;

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

Node* find_min(Binary_Tree*, Node*);
Node* find_max(Binary_Tree*, Node*);

void push_node(Binary_Tree*, void*, DATA_TYPE);
void remove_node(Binary_Tree*, void*, DATA_TYPE);

void show_tree(Binary_Tree*, DATA_TYPE);

#endif
