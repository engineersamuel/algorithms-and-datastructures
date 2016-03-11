def selection(arr):

    for i in range(0, len(arr)):
        # Min idx starts always at the ith element
        min_idx = i

        # Look for any local minima going forward
        for j in range(i+1, len(arr)):
            
            # If we find one, set the min_idx to what we find
            if arr[j] < arr[min_idx]:
                min_idx = j

        # Swap that min with the location at i
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

if __name__ == '__main__':
    arrs = [
        [4, 3, 3, 7, 6, -1, 10, 3, 8, 4],
        [10, 11, 9, 8, 13, 21],
        [-1, -1]
    ]
    print("Selection sort")
    for arr in arrs:
        print("----------------------------------------")
        print("unsorted: {}".format(arr))
        selection(arr)
        print("sorted: {}".format(arr))

    print("\n")
    print("Selection sort")
    for arr in arrs:
        print("----------------------------------------")
        print("unsorted: {}".format(arr))
        selection(arr)
        print("sorted: {}".format(arr))
