"use strict";

function quickSort(arr, start, end) {
    if (start < end) {
        let pIndex = partition(arr, start, end);
        quickSort(arr, start, pIndex - 1);
        quickSort(arr, pIndex + 1, end);
    }
}

function partition(arr, start, end) {
    let pIndex = start;
    const pivot = arr[end];

    for (let i = start; i < end; i++) {
        if (arr[i] <= pivot) {
            let temp = arr[pIndex];
            arr[pIndex] = arr[i];
            arr[i] = temp;

            pIndex += 1;
        }
    }

    let temp = arr[end];
    arr[end] = arr[pIndex];
    arr[pIndex] = temp;

    return pIndex;
}

if (require.main === module) {
    let arr = [8, 9, 7, 5, 2, 4, 6, 1, 3];
    quickSort(arr, 0, arr.length - 1);
    console.log(arr);
}
