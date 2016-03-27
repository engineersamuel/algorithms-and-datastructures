"use strict";

class DFS {
    constructor(g, s) {
        this.marked = [];
        this.count = 0;
        for (let i = 0; i < g.V; i++ ) {
            this.marked.push(false);
        }
        this.dfs(g, s);
    }

    dfs(g, s) {
        this.marked[s] = true;
        this.count += 1;
        for (const v of g.adj[s]) {
            if (!this.marked[v]) {
                this.dfs(g, v);
            }
        }
    }
}

module.exports = DFS;
