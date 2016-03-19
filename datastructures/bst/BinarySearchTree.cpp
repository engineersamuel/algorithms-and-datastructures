#include <iostream>

using namespace std;

struct Node {
    string key;
    int val;
    Node* left;
    Node* right;
    int n;
};

class BinarySearchTree {
private:
    Node *root;
    int get(Node *, string);
    Node * put(Node *, string, int);
public:
    int get(string);
    void put(string, int);
    int size(Node *);
};

int BinarySearchTree::size(Node *node) {
    if (node == nullptr) {
        return 0;
    }
    return node->n;
}

int BinarySearchTree::get(string key) {
    return get(root, key);
}

int BinarySearchTree::get(Node *node, string key) {
    if (node == nullptr) {
        return -1;
    }
    if (key == node->key) {
        return node->val;
    } else if (key < node->key) {
        return this->get(node->left, key);
    } else {
        return this->get(node->right, key);
    }
}

void BinarySearchTree::put(string key, int val) {
    root = put(root, key, val);
}
Node * BinarySearchTree::put(Node *node, string key, int val) {
    if (node == nullptr) {
        Node *n = new Node();
        *n = {key, val, nullptr, nullptr, 1};
        return n;
    }

    if (key == node->key) {
        node->val = val;
    } else if (key < node->key) {
        node->left = put(node->left, key, val);
    } else {
        node->right = put(node->right, key, val);
    }
    node->n = size(node->left) + size(node->right) + 1;
    return node;

}

int main() {
    BinarySearchTree *bst = new BinarySearchTree();
    bst->put("S", 0);
    bst->put("E", 1);
    bst->put("A", 2);
    bst->put("R", 3);
    bst->put("C", 4);
    bst->put("H", 5);
    bst->put("E", 6);
    bst->put("X", 7);
    bst->put("A", 8);
    bst->put("M", 9);
    bst->put("P", 10);
    bst->put("L", 11);
    bst->put("E", 12);

    cout << "X is at: " << bst->get("X") << endl;
    cout << "E is at: " << bst->get("E") << endl;

    return 0;
}
