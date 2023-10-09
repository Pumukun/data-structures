var llNode = /** @class */ (function () {
    function llNode(pdata) {
        this.data = pdata;
    }
    return llNode;
}());
var LinkedList = /** @class */ (function () {
    function LinkedList() {
        this.head = null;
    }
    LinkedList.prototype.insert = function (pdata) {
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
    };
    LinkedList.prototype.pop = function () {
        if (this.head === null) {
            return;
        }
        var tmpNode = this.head;
        while (tmpNode.next !== null) {
            tmpNode = tmpNode.next;
        }
        tmpNode = null;
        return;
    };
    return LinkedList;
}());
