"use strict";

function selection(arr) {
    for (let i = 0; i < arr.length; i++) {
        let min = i;
        for (let j = i + 1; j < arr.length; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        let temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

if (require.main === module) {
    console.log("Selection sort");
    let arr = [8, 9, 7, 5, 2, 4, 6, 1, 3];
    selection(arr);
    console.log(arr);
}
