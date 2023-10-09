using System;

namespace ll {
    class Node<T> {
        public T data;
        public Node<T> next;

        public Node(T pdata) {
            data = pdata;
        }
    }

    class LinkedList<T> {
        public Node<T> head;

        public LinkenList() {
            head = null;
        }

        public void push(T pdata) {
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
            Node<T> tmpNode = head;
            while (tmpNode.next != null) {
                tmpNode = tmpNode.next;
            }
            tmpNode = null;
            return;
        }
    }
}
