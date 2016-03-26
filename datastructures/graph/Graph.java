import java.util.ArrayList;
import java.util.List;


public class Graph {
    private int V;
    private int E;
    private List<Integer>[] adj;

    public Graph(int V) {
        this.V = V; this.E = 0;
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
        adj[w].add(v);
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
        Graph g = new Graph(13);
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
        System.out.println(g);
        System.out.println("Testing connectedness for v: " + 0);
        g.testConnectedness(0);
        System.out.println("Testing connectedness for v: " + 9);
        g.testConnectedness(9);
    }
}
