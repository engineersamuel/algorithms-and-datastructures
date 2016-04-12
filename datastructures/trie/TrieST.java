import java.util.Deque;
import java.util.LinkedList;
import java.util.Queue;

public class TrieST<Value> {
    private static int R = 256;
    private Node root = new Node();
    private static class Node {
        private Object val;
        private Node[] next = new Node[R];
    }

    public int size() {
        return size(root);
    }

    private int size(Node x) {
        if (x == null) return 0;
        int count = 0;
        if (x.val != null) {
            count += 1;
        }
        for (char c = 0; c < R; c++) {
            count += size(x.next[c]);
        }
        return count;
    }

    public Value get(String key) {
        Node x = get(root, key, 0);
        if (x == null) return null;
        return (Value) x.val;
    }

    private Node get(Node x, String key, int d) {
        if (x == null) {
            return null;
        }
        if (d == key.length()) {
            return x;
        }
        char c = key.charAt(d);
        return get(x.next[c], key, d+1);
    }

    public void put(String key, Value val) {
        root = put(root, key, val, 0);
    }

    private Node put(Node x, String key, Value val, int d) {
        if (x == null) {
            x = new Node();
        }
        if (d == key.length()) {
            x.val = val;
            return x;
        }
        char c = key.charAt(d);
        x.next[c] = put(x.next[c], key, val, d+1);
        return x;
    }

    public Iterable<String> keys() {
        return keysWithPrefix("");
    }

    public Iterable<String> keysWithPrefix(String pre) {
        Deque<String> q = new LinkedList<>();
        collect(get(root, pre, 0), pre, q);
        return q;
    }
    private void collect(Node x, String pre, Queue<String> q) {
        if (x == null) {
            return;
        }
        if(x.val != null) {
            q.add(pre);
        }
        for (char c = 0; c < R; c++) {
            collect(x.next[c], pre + c, q);
        }
    }

    public static void main(String[] args) {
        TrieST<Integer>  st = new TrieST<>();
        st.put("she", 0);
        st.put("sells", 1);
        st.put("sea", 2);
        st.put("shells", 3);
        st.put("by", 4);
        st.put("the", 5);
        st.put("sea", 6);
        st.put("shore", 7);

        if (st.size() < 100) {
            System.out.println("keys(\"\"):");
            for (String key : st.keys()) {
                System.out.println(key + " " + st.get(key));
            }
            System.out.println();
        }
    }
}
