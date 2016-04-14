#include <iostream>
#include "TrieST.hpp"

using namespace std;

int TrieST::get(std::string key) {
    Node *x = get(root, key, 0);
    return x->val;
}

Node* TrieST::get(Node *node, std::string key, int d) {
    if (node == nullptr) return nullptr;
    if (d == key.size()) {
        return node;
    }
    char &c = key.at(d);
    return get(node->next[c], key, d+1);
}

void TrieST::put(std::string key, int val) {
    root = put(root, key, val, 0);
}

Node* TrieST::put(Node *node, std::string key, int val, int d) {
    if (node == nullptr) {
        node = new Node();
    }
    if (d == key.size()) {
        node->val = val;
        return node;
    }
    int c = key.at(d);
    node->next[c] = put(node->next[c], key, val, d+1);
    return node;
}

std::queue<std::string> TrieST::keys() {
    return keysWithPrefix("");
}

std::queue<std::string> TrieST::keysWithPrefix(std::string pre) {
    std::queue<std::string> q;
    collect(get(root, pre, 0), pre, &q);
    return q;

}

void TrieST::collect(Node *node, std::string pre, std::queue<std::string> *q) {
    if (node == nullptr) return;
    if (node->val != -1) {
        q->push(pre);
    }
    for (int c = 0; c < R; c++) {
        collect(node->next[c], pre + (char)c, q);
    }
}


int main() {
    TrieST *st = new TrieST();
    st->put("she", 0);
    st->put("sells", 1);
    st->put("sea", 2);
    st->put("shells", 3);
    st->put("by", 4);
    st->put("the", 5);
    st->put("sea", 6);
    st->put("shore", 7);

    cout << "keys(\"\"):\n";
    auto q = st->keys();
    while (!q.empty()) {
        auto key = q.front();
        cout << key << " " << st->get(key) << "\n";
        q.pop();
    }
}
