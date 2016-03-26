i#include "Graph.hpp"
#include "DFS.hpp"

using namespace std;

Graph::Graph(int V) {
    this->V = V;
    this->adj = vector< vector<int> >(V);
    for (int i = 0; i < this->adj.size(); i++) {
        this->adj[i] = vector<int>{};
    }
}

void Graph::addEdge(int v, int w) {
    this->adj[v].push_back(w);
    this->adj[w].push_back(v);
    this->E += 1;
}

int Graph::getV() {
    return V;
}

int Graph::getE() {
    return E;
}

vector< vector<int> >* Graph::getAdj() {
    return &adj;
}

void Graph::print() {
    cout << "Vertices: " << V << ", Edges: " << E << std::endl;
    for (int i = 0; i < V; i++) {
        cout << i << ": ";
        for (auto& j : adj[i]) {
            cout << j << " ";
        }
        cout << std::endl;
    }
}


void Graph::testConnectedness(int v) {
    DFS *dfs = new DFS(this, v);

    for (int i = 0; i < V; i++) {
        if (dfs->getMarked()->at(i) == true) {
            cout << i << " ";
        }
    }

    if (dfs->getCount() != V) {
        cout << "NOT ";
    }
    cout << "connected" << endl;
}

int main() {
    Graph *g = new Graph(13);
    g->addEdge(0, 5);
    g->addEdge(4, 3);
    g->addEdge(0, 1);
    g->addEdge(9, 12);
    g->addEdge(6, 4);
    g->addEdge(5, 4);
    g->addEdge(0, 2);
    g->addEdge(11, 12);
    g->addEdge(9, 10);
    g->addEdge(0, 6);
    g->addEdge(7, 8);
    g->addEdge(9, 11);
    g->addEdge(5, 3);
    g->print();
    cout << "Testing connectedness for v: " << 0 << endl;
    g->testConnectedness(0);
    cout << "Testing connectedness for v: " << 9 << endl;
    g->testConnectedness(9);
    return 0;
}
