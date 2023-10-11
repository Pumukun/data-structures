public class Node<T> {
    public T data;
    public Node<T> next;
    
    public Node(T data) {
        this.data = data;
        this.next = null;
    }
}

public class LinkedList<T> {
    public Node<T> head;

    public LinkedList() {
        head = null;   
    }

    public void insert(T pdata) {
        Node<T> newNode = new Node<T>(pdata);
        if (head == null) {
            head = newNode;
            return;
        }

        Node<T> tmpNode = head;
        while (tmpNode.next != null) {
            tmpNode = tmpNode.next;
        }

        tmpNode.next = newNode;
        return;
    }

    public void pop() {
        if (head == null) {
            return;
        }

        if (head.next == null) {
            head = null;
            return;
        }


        Node<T> tmpNode = head;
        while (tmpNode.next.next != null) {
            tmpNode = tmpNode.next;
        }

        tmpNode.next = null;
        return;
    }
}
