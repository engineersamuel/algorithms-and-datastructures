package main

import "fmt"

type Node struct {
    key string
    val int
    left *Node
    right *Node
    N int
}

type BinarySearchTree struct {
    root *Node
}

func (bst *BinarySearchTree) size(node *Node) int {
    if node == nil {
        return 0
    } else {
        return node.N
    }
}

func (bst *BinarySearchTree) get(key string) int {
    return bst.getHelper(bst.root, key)
}
func (bst *BinarySearchTree) getHelper(node *Node, key string) int {
    if node == nil {
        return -1
    }
    if node.key == key {
        return node.val
    } else if key < node.key {
        return bst.getHelper(node.left, key)
    } else {
        return bst.getHelper(node.right, key)
    }
}

func (bst *BinarySearchTree) put(key string, val int) {
    bst.root = bst.putHelper(bst.root, key, val)
}

func (bst *BinarySearchTree) putHelper(node *Node, key string, val int) *Node {
    if node == nil {
        return &Node{key, val, nil, nil, 1}
    }
    if node.key == key {
        node.val = val
        return node
    } else if key < node.key {
        node.left = bst.putHelper(node.left, key, val)
    } else {
        node.right = bst.putHelper(node.right, key, val)
    }
    node.N = bst.size(node.left) + bst.size(node.right) + 1
    return node
}


func main() {
    bst := new(BinarySearchTree)

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

    fmt.Println(fmt.Sprintf("X is at: %d", bst.get("X")));
    fmt.Println(fmt.Sprintf("E is at: %d", bst.get("E")));
}
