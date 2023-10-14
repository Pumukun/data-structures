class llNode {
    data: any;
    next: llNode | null = null;

    constructor(pdata: any) {
        this.data = pdata;
    }
}

class LinkedList {
    head: llNode | null = null;

    insert(pdata: any) {
        let newNode = new llNode(pdata);
        if (this.head === null) {
            this.head = newNode;
            return;
        }

        let tmpNode = this.head;
        while (tmpNode.next !== null) {
            tmpNode = tmpNode.next;
        }
        tmpNode.next = newNode;
        return;
    }

    pop() {
        if (this.head === null) {
            return null;
        }

        if (this.head.next === null) {
            let dataToReturn = this.head.data;
            this.head = null;
            return dataToReturn;
        }

        let tmpNode = this.head;
        while (tmpNode.next !== null && tmpNode.next.next !== null) {
            tmpNode = tmpNode.next;
        }
        let dataToReturn = tmpNode.next?.data ?? null;
        tmpNode.next = null;
        return dataToReturn;
    }
}
