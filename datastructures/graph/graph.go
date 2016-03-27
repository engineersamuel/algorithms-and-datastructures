package main

import (
    "fmt"
    "bytes"
)

type Graph struct {
    V int;
    E int;
    adj [][]int;
}

func newGraph(V int) *Graph {
    g := new(Graph)
    g.V = V;
    g.E = 0;
    g.adj = make([][]int, V);
    for i := range g.adj {
        g.adj[i] = make([]int, 0)
    }

    return g;
}

func (g *Graph) addEdge(v int, w int) {
    g.E += 1
    g.adj[v] = append(g.adj[v], w)
    g.adj[w] = append(g.adj[w], v)
}

func (g *Graph) toString() string {
    var b bytes.Buffer;
    b.WriteString(fmt.Sprintf("Vertices: %d, Edges: %d\n", g.V, g.E));
    for i := range g.adj {
        b.WriteString(fmt.Sprintf("%d: ", i));
        for j := range g.adj[i] {
            b.WriteString(fmt.Sprintf("%d ", g.adj[i][j]));
        }
        b.WriteString("\n");
    }
    return b.String()
}

func (g *Graph) testConnectedness(s int) {
    dfs := makeDFS(g, s);
    fmt.Println(fmt.Sprintf("v: %d", s))
    for i, x := range dfs.marked {
        if x {
            fmt.Print(fmt.Sprintf("%d ", i))
        }
    }
    //for x := range dfs.marked {
    //  fmt.Println(fmt.Sprintf("marked: %x", dfs.marked[x]))
    //}
    fmt.Println()
    if dfs.count != g.V {
        fmt.Print("NOT ")
    }
    fmt.Print("connected")

}

func main () {
    g := newGraph(13)
    g.addEdge(0, 5);
    g.addEdge(4, 3);
    g.addEdge(0, 1);
    g.addEdge(9, 12);
    g.addEdge(6, 4);
    g.addEdge(5, 4);
    g.addEdge(0, 2);
    g.addEdge(11, 12);
    g.addEdge(9, 10);
    g.addEdge(0, 6);
    g.addEdge(7, 8);
    g.addEdge(9, 11);
    g.addEdge(5, 3);

    fmt.Println(g.toString())
    fmt.Println(fmt.Sprintf("Testing connectedness for v: %d", 0));
    g.testConnectedness(0);
    fmt.Println(fmt.Sprintf("Testing connectedness for v: %d", 9));
    g.testConnectedness(9);

    // go run dfs.go graph.go
}
