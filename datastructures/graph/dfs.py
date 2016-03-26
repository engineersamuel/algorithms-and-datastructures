class DFS:

    count = 0

    def __init__(self, g, s):
        self.marked = []
        for i in range(g.V):
            self.marked.append(False)
        self.dfs(g, s)

    def dfs(self, g, v):
        self.marked[v] = True
        self.count += 1
        for w in g.adj[v]:
            if not self.marked[w]:
                self.dfs(g, w)
