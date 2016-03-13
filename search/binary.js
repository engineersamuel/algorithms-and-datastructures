"use strict";

function binarysearch(arr, num, low, high) {
    if (low > high) return -1;

    let mid = Math.floor(low + ((high - low) / 2));

    if (arr[mid] == num) return mid;
    if (num < arr[mid]) {
        return binarysearch(arr, num, low, mid - 1);
    }
    return binarysearch(arr, num, mid + 1, high);
}

if (require.main === module) {
    let arr = [5, 6, 7, 8, 9, 10, 11, 12, 12, 14, 15],
        num = 15,
        idx = binarysearch(arr, num, 0, arr.length - 1);
    console.log(`num: ${num} is located at index: ${idx}`);
}
