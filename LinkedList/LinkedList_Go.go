package main

import "fmt"

type Node struct {
    data any;
    next *Node;
}

type LinkedList struct {
    head *Node;
}

func (ll *LinkedList) insert(pdata interface{}) {
    new_node := &Node{data: pdata, next: nil}
    if ll.head == nil {
        ll.head = new_node
        return
    }

    tmp_ptr := ll.head
    for tmp_ptr.next != nil {
        tmp_ptr = tmp_ptr.next
    }
    tmp_ptr.next = new_node
}

func (ll *LinkedList) pop() (interface{}, error) {
    if ll.head == nil {
        return nil, fmt.Errorf("list is empty")
    }

    if ll.head.next == nil {
        data := ll.head.data
        ll.head = nil
        return data, nil
    }

    tmp_ptr := ll.head
    for tmp_ptr.next.next != nil {
        tmp_ptr = tmp_ptr.next
    }

    data := tmp_ptr.next.data
    tmp_ptr.next = nil
    return data, nil
}

