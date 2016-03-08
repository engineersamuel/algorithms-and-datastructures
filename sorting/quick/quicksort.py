def quickSort(arr, start, end):
    if start < end:
        pIdx = partition(arr, start, end)
        quickSort(arr, start, pIdx - 1)
        quickSort(arr, pIdx + 1, end)


def partition(arr, start, end):
    pIdx = start
    pivot = arr[end]

    for i in xrange(start, end):
        if arr[i] < pivot:
            arr[i], arr[pIdx] = arr[pIdx], arr[i]
            pIdx += 1

    arr[pIdx], arr[end] = arr[end], arr[pIdx]
    return pIdx


if __name__ == '__main__':
    arrs = [
        [4, 3, 3, 7, 6, -1, 10, 3, 8, 4],
        [10, 11, 9, 8, 13, 21],
        [99, 87, 76, 65, 54, 43, 32, 21, 10, -1],
    ]
    for arr in arrs:
        print("unsorted: {}".format(arr))
        quickSort(arr, 0, len(arr) - 1)
        print("sorted: {}".format(arr))
