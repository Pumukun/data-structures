#ifndef LINKEDLIST_C_H
#define LINKEDLIST_C_H

#include <stdlib.h>

typedef struct Node {
    void* data;
    Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

void create_list(LinkedList *ll) {
    ll->head = nullptr;
}

void insert(LinkedList *ll, void* pdata) {
    Node* new_node;
    new_node->data = pdata;
    new_node->next = nullptr;

    if (ll->head == nullptr) {
        ll->head = new_node;
        return;
    }

    Node* tmp_ptr = ll->head;
    while (tmp_ptr->next != nullptr) {
        tmp_ptr = tmp_ptr->next;
    }

    tmp_ptr->next = new_node;
}

void pop(LinkedList* ll) {
    if (ll->head == nullptr) {
        return;
    }

    Node* tmp_ptr = ll->head;
    while (tmp_ptr->next != nullptr) {
        tmp_ptr = tmp_ptr->next;
    }
    free(tmp_ptr);
}

#endif
