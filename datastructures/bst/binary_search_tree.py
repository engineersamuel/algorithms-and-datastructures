class Node:
    def __init__(self, key, val, left=None, right=None, n=0):
        self.key = key
        self.val = val
        self.left = left
        self.right = right
        self.n = n


class BinarySearchTree:
    def __init__(self):
        self.root = None

    def size(self, node):
        if not node:
            return 0
        return node.n

    def put(self, key, val):
        self.root = self._put(self.root, key, val)

    def _put(self, node, key, val):
        if not node: return Node(key, val, n=1)

        if node.key == key:
            node.val = val
        elif key < node.key:
            node.left = self._put(node.left, key, val)
        else:
            node.right = self._put(node.right, key, val)

        node.N = self.size(node.left) + self.size(node.right) + 1
        return node

    def get(self, key):
        return self._get(self.root, key)

    def _get(self, node, key):
        if not node: return -1
        if node.key == key:
            return node.val
        elif key < node.key:
            return self._get(node.left, key)
        else:
            return self._get(node.right, key)

if __name__ == '__main__':
    bst = BinarySearchTree()

    bst.put("S", 0)
    bst.put("E", 1)
    bst.put("A", 2)
    bst.put("R", 3)
    bst.put("C", 4)
    bst.put("H", 5)
    bst.put("E", 6)
    bst.put("X", 7)
    bst.put("A", 8)
    bst.put("M", 9)
    bst.put("P", 10)
    bst.put("L", 11)
    bst.put("E", 12)

    print("X is at: {}".format(bst.get("X")))
    print("E is at: {}".format(bst.get("E")))
