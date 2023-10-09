#pragma once

template<typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node() = default;
    Node(T& pdata): data(pdata) {}
    ~Node() = default;
};

template<typename T>
class LinkedList {
public:
    Node<T>* head;

    LinkedList(): head(nullptr) {}
    
    ~LinkedList() = default;

    void insert(T& pdata) {
        Node<T>* new_node = new Node<T>(pdata);
        if (head == nullptr) {
            head = new_node;
            return;
        }

        Node<T>* tmp_ptr = head; 
        while (tmp_ptr->next != nullptr) {
            tmp_ptr = tmp_ptr->next;
        }
        tmp_ptr->next = new_node;
        return;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }

        Node<T>* tmp_ptr = head;
        while (tmp_ptr->next != nullptr) {
            tmp_ptr = tmp_ptr->next;
        }
        delete tmp_ptr;
        return;
    }
};

