"use strict";

// function Node (key, val, left, right, n=1) {
//     this.key = key;
//     this.val = val;
//     this.left = left;
//     this.right = right;
//     this.n = n;
// }
class Node  {
    constructor(key, val, left, right, n=1) {
        this.key = key;
        this.val = val;
        this.left = left;
        this.right = right;
        this.n = n;
    }
}

class BinarySearchTree {
    constuctor() {
        this.root = null;
    }

    size(node) {
        if (!node) return 0;
        return node.n;
    }

    get(key) {
        return this._get(this.root, key);
    }
    _get(node, key) {
        if (node == null) return -1;
        if (node.key == key) {
            return node.val;
        } else if (key < node.key) {
            return this._get(node.left, key);
        } else {
            return this._get(node.right, key);
        }

    }

    put(key, val) {
        this.root = this._put(this.root, key, val);
    }
    _put(node, key, val) {
        if(!node) return new Node(key, val);
        if(key == node.key) {
            node.val = val
        } else if (key < node.key) {
            node.left = this._put(node.left, key, val);
        } else {
            node.right = this._put(node.right, key, val);
        }

        node.n = this.size(node.left) + this.size(node.right) + 1;
        return node;
    }
}

if (require.main === module) {
    let bst = new BinarySearchTree();
    bst.put("S", 0);
    bst.put("E", 1);
    bst.put("A", 2);
    bst.put("R", 3);
    bst.put("C", 4);
    bst.put("H", 5);
    bst.put("E", 6);
    bst.put("X", 7);
    bst.put("A", 8);
    bst.put("M", 9);
    bst.put("P", 10);
    bst.put("L", 11);
    bst.put("E", 12);

    console.log(`X is at: ${bst.get("X")}`);
    console.log(`E is at: ${bst.get("E")}`);
}
