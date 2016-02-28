"use strict";

function merge_sort(arr, low, high) {
    if (low < high) {
        let mid = Math.floor((low + high) / 2);
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high)
    }
}

function merge(arr, low, mid, high) {
    let temp = [];

    // Fill the array null
    for (let i = 0; i < (high - low + 1); i++) {
        temp[i] = null;
    }

    let left = low,
        right = mid + 1,
        k = 0;

    // While anything is unsorted sort it!
    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[k] = arr[left];
            left += 1;
        } else {
            temp[k] = arr[right];
            right += 1;
        }
        k += 1
    }

    // If there are any remaining elements in left, they are > than all elments copied from right, so just copy
    // them to the end
    if (left <= mid) {
        while (left <= mid) {
            temp[k] = arr[left];
            left += 1;
            k += 1
        }
    } else if (right <= high) {
        while (right <= high) {
            temp[k] = arr[right];
            right += 1;
            k += 1
        }
    }

    // Copy the sorted arr back into the main arr
    for (let i = 0; i < temp.length; i++) {
        arr[i + low] = temp[i]
    }
}

function merge_sort_rec(arr) {
    if (arr.length <= 1) {
        return arr;
    }
    let mid = Math.floor(arr.length / 2);
    // merge sort the left
    let left = merge_sort_rec(arr.slice(0, mid));
    // merge sort the right
    let right = merge_sort_rec(arr.slice(mid));
    // merge it!
    return merge_rec(left, right)
}
function merge_rec(left, right) {
    if (!left || left.length == 0) return right;
    if (!right || right.length == 0) return left;

    if (left[0] < right[0]) {
        return [left[0], ...merge_rec(left.slice(1), right)];
    }
    return [right[0], ...merge_rec(left, right.slice(1))];
}

if (require.main === module) {
    console.log("Merge sort partially recursive");
    let arr = [8, 9, 7, 5, 2, 4, 6, 1, 3];
    merge_sort(arr, 0, arr.length - 1);
    console.log(arr);
    console.log("Merge sort fully recursive");
    arr = [8, 9, 7, 5, 2, 4, 6, 1, 3];
    console.log(merge_sort_rec(arr));
}
