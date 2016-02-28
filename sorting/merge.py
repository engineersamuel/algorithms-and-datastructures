def merge_sort(arr, low, high):
    if low < high:
        middle = (low + high) // 2
        merge_sort(arr, low, middle)
        merge_sort(arr, middle + 1, high)
        merge(arr, low, middle, high)


def merge(arr, low, mid, high):
    # Since python doesn't natively have arrays, create a list of all 0s.  The 0s aren't important
    temp = [None] * (high - low + 1)
    left = low
    right = mid + 1
    # k tracks the current position of the merge
    k = 0

    while (left <= mid) and (right <= high):

        # if the left idx val is < right, use the left, otherwise use the right
        if arr[left] < arr[right]:
            temp[k] = arr[left]
            left += 1
        else:
            temp[k] = arr[right]
            right += 1
        # Increment the position
        k += 1

    # Now, if we have a disbalance in the size between the left and right halves, have to copy the remaining values

    # If the left idx is less than the mid that means left has un-inserted values, which we know must all be greater
    # than what is already in the array because that means all of right was exhausted and was smaller
    if left <= mid:
        while left <= mid:
            temp[k] = arr[left]
            left += 1
            k += 1
    # Otherwise left was exhausted and was all smaller, which means everything remaining the right is larger, just
    # copy it straight in
    elif right <= high:
        while right <= high:
            temp[k] = arr[right]
            right += 1
            k += 1

    # Now, copy this merged/sorted temp back into the unsorted argument array
    for i in xrange(len(temp)):
        arr[low + i] = temp[i]


def merge_sort_rec(arr):
    if len(arr) <= 1:
        return arr
    mid = len(arr) // 2
    left = merge_sort_rec(arr[:mid])
    right = merge_sort_rec(arr[mid:])
    return merge_rec(left, right)


def merge_rec(arr_left, arr_right):
    # If no left hand side then return the sorted right
    if not arr_left:
        return arr_right
    # If no right hand side then return the sorted left
    if not arr_right:
        return arr_left
    
    # If the first element of the left is < the first element of the right then return the left first elem + the rest 
    if arr_left[0] < arr_right[0]:
        return [arr_left[0]] + merge_rec(arr_left[1:], arr_right)
    # If the first element of the right is < the first element of the left then return the right first elem + the rest
    return [arr_right[0]] + merge_rec(arr_left, arr_right[1:])


if __name__ == '__main__':
    arrs = [
        [4, 3, 3, 7, 6, -1, 10, 3, 8, 4],
        [10, 11, 9, 8, 13, 21],
        [-1, -1]
    ]
    print("Single recursive")
    for arr in arrs:
        print("----------------------------------------")
        print("unsorted: {}".format(arr))
        merge_sort(arr, 0, len(arr) - 1)
        print("sorted: {}".format(arr))

    print("\n")
    print("Double recursive")
    for arr in arrs:
        print("----------------------------------------")
        print("unsorted: {}".format(arr))
        merge_sort_rec(arr)
        print("sorted: {}".format(arr))

