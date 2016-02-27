def insertion(arr):
    for i in range(1, len(arr)):
        ctr = i
        while ctr > 0 and arr[ctr] < arr[ctr - 1]:
            arr[ctr - 1], arr[ctr] = arr[ctr], arr[ctr - 1]
            ctr -= 1


if __name__ == '__main__':
    arr = [8, 9, 7, 5, 2, 4, 6, 1, 3]
    insertion(arr)
    assert arr == [1, 2, 3, 4, 5, 6, 7, 8, 9]
