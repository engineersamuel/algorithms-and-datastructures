#include <iostream>
#include <vector>

using namespace std;


struct Node;

struct Node {
    string key;
    int val;
    Node *next;
};


class SequentialSearchST {

private:
    Node *first;

public:
    SequentialSearchST();
    int get(string);
    void put(string, int);
};

int SequentialSearchST::get(string key) {
    for (Node *x = first; x != nullptr; x = x->next) {
        if (x->key == key) {
            return x->val;
        }
    }

    return -1;
}

void SequentialSearchST::put(string key, int val) {
    for (Node *x = first; x != nullptr; x = x->next) {
        if (x->key == key ) {
            x->val = val;
            return;
        }
    }
    // TODO -- I suspect there is a more compact way to do this, need to figure it out.
    Node *temp = new Node();
    temp->key = key;
    temp->val = val;
    temp->next = first;
    first = temp;
}

SequentialSearchST::SequentialSearchST() {
    return;
}


int main() {

     SequentialSearchST *st = new SequentialSearchST();

    st->put("a", 2);
    st->put("b", 3);
    st->put("c", 4);

    cout << "c: " << st->get("c") << endl;
    cout << "b: " << st->get("b") << endl;
    cout << "a: " << st->get("a") << endl;

    return 0;
}
