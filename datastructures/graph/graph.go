import java.util.ArrayList;
import java.util.List;


public class Graph {
    private int V;
    private int E;
    private List<Integer>[] adj;

    public Graph(int V) {
        this.V = V;
        this.E = 0;
        adj = (List<Integer>[]) new ArrayList[V];
        //adj = new ArrayList<Integer>[V];
        for (int v = 0; v < V; v++) {
            adj[v] = new ArrayList<>();
        }
    }

    public int V() {
        return V;
    }

    public int E() {
        return E;
    }

    public void addEdge(int v, int w) {
        adj[v].add(w);
//        adj[w].add(v);
        E++;
    }

    public Iterable<Integer> adj(int v) {
        return adj[v];
    }

    public String toString() {
        String s = V + " vertices, " + E + " edges\n";
        for (int v = 0; v < V; v++) {
            s += v + ": ";
            for (int w : this.adj(v)) {
                s += w + " ";
            }
            s += "\n";
        }
        return s;
    }

    public void testConnectedness(int w) {
        DFS search = new DFS(this, w);
        for (int v = 0; v < V(); v++) {
            if (search.marked(v)) {
                System.out.print(v + " ");
            }
        }
        System.out.println();

        if (search.count() != V()) {
            System.out.print("NOT ");
        }
        System.out.println("connected");
    }

    public static void main(String[] args) {
        // V E
        Graph g = new Graph(6);
        g.addEdge(0, 5);
        g.addEdge(2, 4);
        g.addEdge(2, 3);
        g.addEdge(1, 2);
        g.addEdge(0, 1);
        g.addEdge(3, 4);
        g.addEdge(3, 5);
        g.addEdge(0, 2);

        System.out.println(g);
        int s = 0;
        System.out.println("Testing connectedness for v: " + s);
        g.testConnectedness(s);
        s = 3;
        System.out.println("Testing connectedness for v: " + s);
        g.testConnectedness(s);

        s = 0;
        System.out.println("Testing paths to " + s);
        Paths path = new DFSPathFinder(g, s);
        for (int v = 0; v < g.V(); v++) {
            if (path.hasPathTo(v)) {
                System.out.print(s + " to " + v + ": ");
                for (int x : path.pathTo(v)) {
                    if (x == s) System.out.print(x);
                    else        System.out.print(x + "-");
                }
                System.out.println();
            }
        }
    }
}
