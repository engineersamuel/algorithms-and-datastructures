from __future__ import print_function


class MaxPQ:

    def __init__(self, arr, N):
        self._arr = arr
        self.N = N
        for i in range(N/2, 0, -1):
            self.down(i)

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

            # run max heapify
            for i in range(self.N/2, 0, -1):
                self.down(i)


if __name__ == '__main__':
    arr = [None, 1, 16, 4, 10, 4, 7, 9, 3, 2, 8, 1, 5]
    print(len(arr))
    print(arr)
    maxpq = MaxPQ(arr, len(arr) - 1)
    print(maxpq._arr)
    for i in maxpq.sort():
        print(i, end=" ")
