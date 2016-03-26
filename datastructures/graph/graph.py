from __future__ import print_function
from dfs import DFS


class Graph:

    E = 0

    def __init__(self, V):
        self.V = V
        self.adj = []
        # Initialize the adjacency list
        for i in range(V):
            self.adj.append([])

    def add_edge(self, v, w):
        self.adj[v].append(w)
        self.adj[w].append(v)
        self.E += 1

    def test_connectedness(self, v):
        dfs = DFS(self, v)
        for i in range(self.V):
            if dfs.marked[i]:
                print(str(i) + " ", end="")

        if dfs.count != self.V:
            print("NOT ", end="")

        print("connected")

    def __str__(self):
        s = str(self.V) + " vertices, " + str(self.E) + " edges\n"
        for i in range(self.V):
            s += str(i) + ": "
            for j in range(len(self.adj[i])):
                s += str(self.adj[i][j]) + " "
            s += "\n"
        return s


if __name__ == '__main__':
    g = Graph(13)
    g.add_edge(0, 5)
    g.add_edge(4, 3)
    g.add_edge(0, 1)
    g.add_edge(9, 12)
    g.add_edge(6, 4)
    g.add_edge(5, 4)
    g.add_edge(0, 2)
    g.add_edge(11, 12)
    g.add_edge(9, 10)
    g.add_edge(0, 6)
    g.add_edge(7, 8)
    g.add_edge(9, 11)
    g.add_edge(5, 3)
    print(g)
    print("Testing connectedness for v: " + str(0))
    g.test_connectedness(0)
    print("Testing connectedness for v: " + str(9))
    g.test_connectedness(9)
