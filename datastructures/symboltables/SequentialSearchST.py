class Node:
    def __init__(self, key, val, next):
        self.key = key
        self.val = val
        self.next = next


class SequentialSearchST:
    first = None

    def __init__(self):
        pass

    def get(self, key):

        temp = self.first
        while temp:
            if temp.key is key:
                return temp.val

            # Advance the temp to the next
            temp = temp.next

        return -1

    def put(self, key, val):

        if not self.first:
            self.first = Node(key, val, None)
            return

        temp = self.first
        while temp:
            if temp.key is key:
                temp.val = val
            temp = temp.next

        self.first = Node(key, val, self.first)


if __name__ == '__main__':
    st = SequentialSearchST()

    st.put("a", 0)
    st.put("b", 1)
    st.put("c", 2)

    print(st.get("c"))
    print(st.get("b"))
    print(st.get("a"))

