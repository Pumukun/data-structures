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
    ll->head = NULL;
}

void insert(LinkedList *ll, void* pdata) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) { return; }
    new_node->data = pdata;
    new_node->next = NULL;

    if (ll->head == NULL) {
        ll->head = new_node;
        return;
    }

    Node* tmp_ptr = ll->head;
    while (tmp_ptr->next != NULL) {
        tmp_ptr = tmp_ptr->next;
    }

    tmp_ptr->next = new_node;
}

void pop(LinkedList* ll) {
    if (ll->head == NULL) {
        return;
    }

    if (ll->head->next == NULL) {
        ll->head = NULL;
        return;
    }

    Node* tmp_ptr = ll->head;
    while (tmp_ptr->next->next != NULL) {
        tmp_ptr = tmp_ptr->next;
    }
    free(tmp_ptr->next);
    tmp_ptr->next = NULL;
}

#endif
