public class BinarySearchTree<Key extends Comparable<Key>, Value> {

    private Node root;

    private class Node {
        private Key key;
        private Value val;
        private Node left, right;
        private int N;
        public Node(Key key, Value val, int N) {
            this.key = key;
            this.val = val;
            this.N = N;
        }
    }

    public int size() {
        return size(root);
    }
    public int size(Node node) {
        if (node == null) {
            return 0;
        } else {
            return node.N;
        }
    }

    public Value get(Key key) {
        return get(root, key);
    }
    private Value get(Node n, Key key) {
        if (n == null) return null;
        int cmp = key.compareTo(n.key);
        if (cmp < 0) {
            return get(n.left, key);
        } else if (cmp > 0) {
            return get(n.right, key);
        } else {
            return n.val;
        }
    }

    public void put(Key key, Value val) {
        // It is fine to assign the root here since it will only ever be assigned for the very first put
        // after that it won't be reassigned
        root = put(root, key, val);
    }
    private Node put(Node n, Key key, Value val) {
        if (n == null) return new Node(key, val, 1);
        int cmp = key.compareTo(n.key);
        if (cmp < 0) {
            n.left = put(n.left, key, val);
        } else if (cmp > 0) {
            n.right = put(n.right, key, val);
        } else {
            n.val = val;
        }
        n.N = size(n.left) + size(n.right) + 1;
        return n;
    }
    
    public static void main(String[] args) {
        BinarySearchTree<String, Integer> bst = new BinarySearchTree<>();
        bst.put("S", 0);
        bst.put("E", 1);
        bst.put("A", 2);
        bst.put("R", 3);
        bst.put("C", 4);
        bst.put("H", 5);
        bst.put("E", 6);
        bst.put("X", 7);
        bst.put("A", 8);
        bst.put("M", 9);
        bst.put("P", 10);
        bst.put("L", 11);
        bst.put("E", 12);

        System.out.println("X is at: " + bst.get("X"));
        System.out.println("E is at: " + bst.get("E"));
    }
}
