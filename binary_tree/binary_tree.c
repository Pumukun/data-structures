#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "binary_tree.h"

// private field

int __compare_data(const void* a, const void* b, DATA_TYPE type) {
    switch (type) {
        case INT:
            return *(int*)a - *(int*)b;
        case FLOAT: {
            float diff = *(float*)a - *(float*)b;
            return (diff > 0) - (diff < 0);
        }
        case CHAR:
            return *(char*)a - *(char*)b;
        default:
            return 0;
    }
}

Node* __push_r(Binary_Tree* p_tree, Node* n_node, Node* cur_node, DATA_TYPE type) {
    if (n_node == NULL || p_tree == NULL) {
        return NULL;
    }
    if (p_tree->root == NULL) {
        p_tree->root = n_node;
        n_node->parent = NULL;
        ++p_tree->size;
        return n_node;
    }

    int cmp = __compare_data(cur_node->data, n_node->data, type);
    if (cmp > 0) {
        if (cur_node->left_ch != NULL) {
            return __push_r(p_tree, n_node, cur_node->left_ch, type);
        } else {
            cur_node->left_ch = n_node;
            n_node->parent = cur_node;
        }
    } else if (cmp < 0) {
        if (cur_node->right_ch != NULL) {
            return __push_r(p_tree, n_node, cur_node->right_ch, type);
        } else {
            cur_node->right_ch = n_node;
            n_node->parent = cur_node;
        }
    }
    ++p_tree->size;
    return n_node;
}

Node* __remove_r(Binary_Tree* p_tree, void* p_data, Node* cur_node, DATA_TYPE type) {
    if (cur_node == NULL) {
        return cur_node;
    }
    
    Node* xd_node = new_node(NULL, NULL, NULL, p_data);
    int cmp = __compare_data(cur_node->data, xd_node->data, type);
    if (cmp > 0) {
        cur_node->left_ch = __remove_r(p_tree, p_data, cur_node->left_ch, type); 
    } else if (cmp < 0) {
        cur_node->right_ch = __remove_r(p_tree, p_data, cur_node->right_ch, type);
    } else if (cur_node->left_ch != NULL && cur_node->right_ch != NULL) {
        Node* successor = find_min(p_tree, cur_node->right_ch); 
        cur_node->data = successor->data;
        cur_node->right_ch = __remove_r(p_tree, successor->data, cur_node->right_ch, type);
    } else {
        Node* child = (cur_node->left_ch != NULL) ? cur_node->left_ch : cur_node->right_ch;
        if (child == NULL) {
            free(cur_node);
            cur_node = NULL;
        } else {
            Node* tmp = cur_node;
            cur_node = child;
            free(tmp);
        }
        --p_tree->size;
    }
    free(xd_node);
    return cur_node;
}


char* __concat(const char* s1, const char* s2) {
    int length = strlen(s1) + strlen(s2) + 1;
    char* result = (char*)malloc(length * sizeof(char));
    if (result == NULL) {
        fprintf(stderr, "malloc fail\nfile: %s\nline: %d", __FILE__, __LINE__);
        exit(1);
    }
    strcpy(result, s1);
    strcat(result, s2);

    return result;
}

void __show_tree(const Node* p_root, char* prefix, int8_t is_left, DATA_TYPE type) {
    if (p_root == NULL) {
        return;
    }
    if (prefix == NULL) {
        prefix = "";
    }
    
    printf("%s", prefix);
    printf("%s", (is_left ? "|-- " : "`-- "));
    switch (type) {
        case INT:
            printf("%d\n", *(int*)p_root->data);
            break;
        case FLOAT:
            printf("%f\n", *(double*)p_root->data);
            break;
        case CHAR:
            printf("%s\n", (char*)p_root->data);
            break;
    }

    __show_tree(p_root->left_ch, __concat(prefix, (is_left ? "|   " : "    ")), 1, type);
    __show_tree(p_root->right_ch, __concat(prefix, (is_left ? "|   " : "    ")), 0, type);
}

// private field end


Node* new_node(Node* p_parent, Node* p_left_ch, Node* p_right_ch, void* p_data) {
    Node* new_n = (Node*)malloc(sizeof(Node));
    new_n->parent = p_parent;
    new_n->left_ch = p_left_ch;
    new_n->right_ch = p_right_ch;
    new_n->data = p_data;
    return new_n;
}

Binary_Tree* new_tree(Node* p_root) {
    Binary_Tree* new_t = (Binary_Tree*)malloc(sizeof(Binary_Tree));
    if (p_root == NULL) {
        new_t->root = NULL;
        new_t->size = 0;
        return new_t;
    }

    new_t->root = p_root;
    new_t->size = 1;
    return new_t;
}

Node* find_min(Binary_Tree* p_tree, Node* cur_node) {
    if (p_tree->root == NULL) {
        return NULL;
    }
    if (cur_node == NULL) {
        cur_node = p_tree->root;
        return cur_node;
    }
    while (cur_node->left_ch != NULL) {
        cur_node = cur_node->left_ch;
    }
    return cur_node;
}

Node* find_max(Binary_Tree* p_tree, Node* cur_node) {
    if (p_tree->root == NULL) {
        return NULL;
    }
    if (cur_node == NULL) {
        cur_node = p_tree->root;
        return cur_node;
    }
    while (cur_node->right_ch != NULL) {
        cur_node = cur_node->right_ch;
    }
    return cur_node;
}

void push_node(Binary_Tree* p_tree, void* p_data, DATA_TYPE type) {
    Node* n_node = new_node(NULL, NULL, NULL, p_data);
    __push_r(p_tree, n_node, p_tree->root, type);
}

void remove_node(Binary_Tree* p_tree, void* p_data, DATA_TYPE type) {
    __remove_r(p_tree, p_data, p_tree->root, type);
}

void show_tree(Binary_Tree* p_tree, DATA_TYPE type) {
    __show_tree(p_tree->root, NULL, 1, type);
}

