
class Node:
    val = None

    def __init__(self, R):
        self.next = []
        for i in range(R):
            self.next.append(None)


class TrieST:

    R = 256
    root = Node(R)

    def __init__(self):
        pass

    def get(self, key):
        x = self.get_helper(self.root, key, 0)
        return x.val if x else None

    def get_helper(self, node, key, d):
        if not node: return None
        if d == len(key): return node
        c = ord(key[d])
        return self.get_helper(node.next[c], key, d+1)

    def put(self, key, val):
        self.root = self.put_helper(self.root, key, val, 0)

    def put_helper(self, node, key, val, d):
        if not node:
            node = Node(self.R)
        if d == len(key):
            node.val = val
            return node
        c = ord(key[d])
        node.next[c] = self.put_helper(node.next[c], key, val, d+1)
        return node

    def keys(self):
        return self.keysWithPrefix("")

    def keysWithPrefix(self, pre):
        q = []
        self.collect(self.get_helper(self.root, pre, 0), pre, q)
        return q

    def collect(self, node, pre, q):
        if node == None: return None
        if node.val != None: q.append(pre)
        for i in range(self.R):
            self.collect(node.next[i], pre + chr(i), q)


if __name__ == '__main__':
    st = TrieST()
    st.put("she", 0)
    st.put("sells", 1)
    st.put("sea", 2)
    st.put("shells", 3)
    st.put("by", 4)
    st.put("the", 5)
    st.put("sea", 6)
    st.put("shore", 7)

    print("keys(\"\"):")
    for key in st.keys():
        print("{} {}".format(key, st.get(key)))
