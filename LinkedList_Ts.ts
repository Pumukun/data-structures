class llNode {
    data: any;
    next: llNode;

    constructor(pdata: any) {
        this.data = pdata;
    }
}

class LinkedList {
    head: llNode;

    constructor() {
        this.head = null;
    }

    insert(pdata: any) {
        var newNode = new llNode(pdata);
        if (this.head === null) {
            this.head = newNode;
            return;
        }

        var tmpNode = this.head;
        while (tmpNode.next !== null) {
            tmpNode = tmpNode.next;
        }
        tmpNode.next = newNode;
        return;
    }

    pop() {
        if (this.head === null) {
            return;
        }

        var tmpNode = this.head;
        while (tmpNode.next !== null) {
            tmpNode = tmpNode.next;
        }
        tmpNode = null;
        return;
    }
}
