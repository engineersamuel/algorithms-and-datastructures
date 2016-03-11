def shell(arr):
    gap = len(arr) // 2
    while gap >= 1:
        for i in xrange(len(arr)):
            if i + gap > len(arr) - 1:
                break
            insertion_sort_gap(arr, i, gap)
        gap //= 2


def insertion_sort_gap(arr, start, gap):
    pos = start + gap
    while pos - gap >= 0 and arr[pos] < arr[pos - gap]:
        arr[pos], arr[pos - gap] = arr[pos - gap], arr[pos]
        pos -= gap


if __name__ == '__main__':
    arrs = [
        [4, 3, 3, 7, 6, -1, 10, 3, 8, 4],
        [10, 11, 9, 8, 13, 21],
        [99, 87, 76, 65, 54, 43, 32, 21, 10, -1],
    ]
    for arr in arrs:
        print("unsorted: {}".format(arr))
        shell(arr)
        print("sorted: {}".format(arr))
