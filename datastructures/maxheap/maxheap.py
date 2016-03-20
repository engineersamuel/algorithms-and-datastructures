from __future__ import print_function


class MaxHeap:

    def __init__(self, arr, N):
        self._arr = arr
        self.N = N
        for i in range(N/2, 0, -1):
            self.down(i)

    def up(self, k):
        # While we aren't at the root and the parent is less than the current node, swap them
        while k > 0 and self._arr[k/2] < self._arr[k]:
            # Swap k/2 and k, i.e swap the parent with the current node
            self._arr[k/2], self._arr[k] = self._arr[k], self._arr[k/2]
            # Now go up to the parent and re-evaluate
            k /= 2

    # O(N)
    def down(self, k):
        # While we aren't at the last leaf.  2*k is the left child
        while 2*k <= self.N:
            # Left child of k
            j = 2*k

            # Choose the greater of the two child nodes
            if j+1 <= self.N and self._arr[j] < self._arr[j+1]:
                j += 1

            # If the parent greater than the greatest child, break, nothing more to do here
            if self._arr[k] > self._arr[j]:
                break

            # Exchange the parent and child
            self._arr[k], self._arr[j] = self._arr[j], self._arr[k]

            # The child is the new parent, and we have another go
            # I.e. whatever child was exchanged with the parent is the new parent
            k = j

    # O(N lg N)
    def sort(self):
        while self.N >= 1:

            yield self._arr[1]

            # Swap the first position with the last
            self._arr[1], self._arr[self.N] = self._arr[self.N], self._arr[1]

            # decrement the size
            self.N -= 1

            # Since just the top was swappd with the end, sink down the top now to the right place
            self.down(1)

            #  I don't believe running run max heapify fully here is necessary
            #for i in range(self.N/2, 0, -1):
            #    self.down(i)


if __name__ == '__main__':
    arr = [None, 1, 16, 4, 10, 4, 7, 9, 3, 2, 8, 1, 5]
    print(len(arr))
    print(arr)
    maxh = MaxHeap(arr, len(arr) - 1)
    print(maxh._arr)
    for i in maxh.sort():
        print(i, end=" ")
