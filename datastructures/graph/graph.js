"use strict";

const DFS = require('./dfs');

class Graph {
    constructor(V) {
        this.V = V;
        this.E = 0;
        this.adj = [];
        for (let i = 0; i < V; i++) {
            this.adj.push([]);
        }
    }

    addEdge(v, w) {
        this.adj[v].push(w);
        this.adj[w].push(v);
        this.E += 1;
    }

    toString() {
        let s = `Vertices: ${this.V}, Edges: ${this.E}\n`;
        for (const i in this.adj) {
            s += `${i}: `;
            for (const w of this.adj[i]) {
                s += `${w} `;
            }
            s += `\n`;
        }
        return s;
    }
    
    testConnectedness(s) {
        const dfs = new DFS(this, s);
        let o = `${s}: `;
        for (const i in dfs.marked) {
            if (dfs.marked[i]) {
                o += `${i} `;
            }
        }
        o += "\n";
        if (dfs.count != this.V) {
            o += "NOT ";
        }
        o += "connected\n";
        console.log(o);
    }
}

if (require.main === module) {

    const g = new Graph(13);
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

    console.log(g.toString());
    console.log(`Testing connectedness for v: 0`);
    g.testConnectedness(0);
    console.log(`Testing connectedness for v: 9`);
    g.testConnectedness(9);    
}
