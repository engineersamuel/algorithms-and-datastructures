def binary_search_itr(arr, num, low, high):
    idx = -1
    while low <= high:
        mid = low + (high - low) / 2

        if arr[mid] == num:
            idx = mid
            break

        if num < arr[mid]:
            high = mid - 1
        else:
            low = mid + 1

    return idx


def binary_search_rec(arr, num, low, high):
    if low > high:
        return -1

    # low +, always remember to low + !
    mid = low + ((high - low) / 2)

    if arr[mid] == num:
        return mid

    if arr[mid] > num:
        return binary_search_rec(arr, num, low, mid - 1)
    else:
        return binary_search_rec(arr, num, mid + 1, high)


if __name__ == '__main__':
    arr = [3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14]
    num = 3
    idx = binary_search_rec(arr, num, 0, len(arr) - 1)
    print("num: {} is at idx: {}".format(num, idx))
    idx = binary_search_itr(arr, num, 0, len(arr) - 1)
    print("num: {} is at idx: {}".format(num, idx))
