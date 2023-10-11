struct Node<T> {
    data: T,
    next: *Node<T>,
}

impl<T> Node<T> {
    fn new(pdata: &T) -> Node<T> {
        Node<T> { pdata, std::ptr::null }
    }
}

struct LinkedList<T> {
    head: *Node<T>,
}

impl<T> LinkedList<T> {
    fn new() -> LinkedList<T> {
        LinkedList<T> { std::ptr::null }
    }

    fn push(&mut self, pdata: &T) {
        let new_node = &Node<T>::new(pdata);
        if (self.head == std::ptr::null) {
            self.head = new_node;
        }

        let *mut tmp_node = self.head;
        while (tmp_node.next != std::ptr:null) {
            tmp_node = tmp_node.next;
        }
        tmp_node.next = new_node;
    }

    fn pop() {

    }
}
