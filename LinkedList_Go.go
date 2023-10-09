package main

type Node struct {
    data any;
    next *Node;
}

type LinkedList struct {
    head *Node;
}

func (ll LinkedList) insert(pdata any) {
    var new_node *Node = &Node{data: pdata, next: nil}
    if ll.head == nil {
        ll.head = new_node
        return
    }

    var tmp_ptr *Node = ll.head
    for tmp_ptr.next != nil {
        tmp_ptr = tmp_ptr.next
    }
    tmp_ptr.next = new_node
}

func (ll LinkedList) pop() {
    if ll.head == nil {
        return
    } 
    
    var tmp_ptr *Node = ll.head
    for tmp_ptr.next != nil {
        tmp_ptr = tmp_ptr.next
    }

    tmp_ptr = nil
}
