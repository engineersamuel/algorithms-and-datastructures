#include <string>
#include <vector>
#include <queue>

#ifndef SANDBOX_TRIEST_HPP
#define SANDBOX_TRIEST_HPP

const int R = 256;

struct Node {
    int val = -1;
    Node* next[R];
};

class TrieST {
private:
    Node *root;
    Node* get(Node *, std::string, int);
    Node* put(Node *, std::string, int, int);

public:
    int size();
    int size(Node *);
    int get(std::string);
    void put(std::string, int);
    std::queue<std::string> keys();
    std::queue<std::string> keysWithPrefix(std::string);
    void collect(Node *, std::string, std::queue<std::string> *);

};

#endif //SANDBOX_TRIEST_HPP
