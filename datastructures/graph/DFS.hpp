#ifndef SANDBOX_DFS_HPP
#define SANDBOX_DFS_HPP

#include "Graph.hpp"

class DFS {
private:
    int count = 0;
    std::vector<bool> marked;
    void dfs(Graph *, int);

public:
    DFS(Graph *, int);
    int getCount();
    std::vector<bool>* getMarked();
};

#endif //SANDBOX_DFS_HPP
