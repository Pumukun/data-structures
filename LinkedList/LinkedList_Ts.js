var llNode = /** @class */ (function () {
    function llNode(pdata) {
        this.next = null;
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
        var _a, _b;
        if (this.head === null) {
            return null;
        }
        if (this.head.next === null) {
            var dataToReturn_1 = this.head.data;
            this.head = null;
            return dataToReturn_1;
        }
        var tmpNode = this.head;
        while (tmpNode.next !== null && tmpNode.next.next !== null) {
            tmpNode = tmpNode.next;
        }
        var dataToReturn = (_b = (_a = tmpNode.next) === null || _a === void 0 ? void 0 : _a.data) !== null && _b !== void 0 ? _b : null;
        tmpNode.next = null;
        return dataToReturn;
    };
    return LinkedList;
}());
