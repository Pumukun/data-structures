class Node:
    def __init__(self, data=None, next=None):
        self.data: any = data
        self.next: Node = next

class LinkedList:
    def __init__(self, head=None):
        self.head: Node = head

    def push(self, pdata):
        new_node = Node(pdata)
        if not self.head:
            self.head = new_node
            return
        
        tmp_ptr: Node = self.head
        while tmp_ptr.next is not None:
            tmp_ptr = tmp_ptr.next
        tmp_ptr.next = new_node

    def pop(self):
        if not self.head:
            return None
        
        if not self.head.next:
            data = self.head.data
            self.head = None
            return data

        tmp_ptr: Node = self.head
        while tmp_ptr.next.next is not None:
            tmp_ptr = tmp_ptr.next

        data = tmp_ptr.next.data
        tmp_ptr.next = None
        return data
