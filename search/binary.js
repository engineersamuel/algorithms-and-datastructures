"use strict";

function binarysearch_itr(arr, num, low, high) {
    let idx = -1, mid;

    while (low <= high) {
        mid = Math.floor(low + (high - low) / 2)

        if (arr[mid] == num) {
            idx = mid;
            break;
        }

        if (num < arr[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return idx;
}

function binarysearch_rec(arr, num, low, high) {
    if (low > high) return -1;

    let mid = Math.floor(low + ((high - low) / 2));

    if (arr[mid] == num) return mid;
    if (num < arr[mid]) {
        return binarysearch_rec(arr, num, low, mid - 1);
    }
    return binarysearch_rec(arr, num, mid + 1, high);
}

if (require.main === module) {
    let arr = [5, 6, 7, 8, 9, 10, 11, 12, 12, 14, 15],
        num = 5,
        idx = binarysearch_rec(arr, num, 0, arr.length - 1);
    console.log(`num: ${num} is located at index: ${idx}`);
    idx = binarysearch_itr(arr, num, 0, arr.length - 1);
    console.log(`num: ${num} is located at index: ${idx}`);
}
