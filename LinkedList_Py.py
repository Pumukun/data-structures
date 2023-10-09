class Node:
    def __init__(self, data=None, next=None):
        self.data: any = data
        self.next: Node = next

class LinkedList:
    def __init__(self, head=None):
        self.head: Node = head

    def push(self, pdata):
        new_node = Node(pdata)
        if self.head == None:
            self.head = new_node
            return
        
        tmp_ptr: Node = self.head
        while tmp_ptr.next != None:
            tmp_ptr = tmp_ptr.next
        tmp_ptr.next = new_node
        return

    def pop():
        tmp_ptr: Node = self.head
        while tmp_ptr.next != None:
            tmp_ptr = tmp_ptr.next
        tmp_ptr = None
        return

