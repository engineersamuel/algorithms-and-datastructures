#include <stdio.h>
#include <vector>
#include <iostream>

#ifndef SANDBOX_GRAPH_HPP
#define SANDBOX_GRAPH_HPP

class Graph {
private:
    int V;
    int E = 0;
    std::vector< std::vector<int> > adj;
public:
    Graph(int);
    void addEdge(int, int);
    int getV();
    int getE();
    std::vector< std::vector<int> >* getAdj();
    void print();
    void testConnectedness(int);
};

// This does not seem to be working yet, I took the const off the const Graph &g, need to re-evaluate
//std::ostream& operator<<(std::ostream &strm, Graph &g) {
//
//    strm << "Vertices: " << g.getV() << ", Edges: " << g.getE() << std::endl;
//    for (int i = 0; i < g.getV(); i++) {
//        strm << i << ": ";
//        for (auto& j : (*g.getAdj())[i]) {
//            strm << j << " ";
//        }
//        strm << std::endl;
//    }
//    return strm;
//}

#endif //SANDBOX_GRAPH_HPP
