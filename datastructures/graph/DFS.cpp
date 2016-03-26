#include "DFS.hpp"

using namespace std;

DFS::DFS(Graph *g, int s) {
    marked = vector<bool> (g->getV(), false);
    dfs(g, s);
}

void DFS::dfs(Graph *g, int v) {
    marked[v] = true;
    count += 1;
    for(int w : g->getAdj()->at(v)) {
        if (!marked[w]) {
            dfs(g, w);
        }
    }
}

int DFS::getCount() {
    return count;
}

vector<bool>* DFS::getMarked() {
    return &marked;
}
