package main

type DFS struct {
    marked []bool;
    count int;
}

func makeDFS(g *Graph, s int) *DFS {
    dfs := new(DFS)
    dfs.marked = make([]bool, g.V)
    dfs.dfs(g, s)
    return dfs
}

func (dfs *DFS) dfs(g *Graph, v int) {
    dfs.marked[v] = true
    dfs.count += 1
    for _, w := range g.adj[v] {
        if !dfs.marked[w] {
            dfs.dfs(g, w)
        }
    }
}
