"use strict";

function insertion(arr) {
    for (let i = 1; i < arr.length; i++) {
        let ctr = i;
        while (ctr > 0 && arr[ctr] < arr[ctr - 1]) {
            let temp = arr[ctr - 1];
            arr[ctr - 1] = arr[ctr];
            arr[ctr] = temp;
            ctr -= 1;
        }
    }
}

if (require.main === module) {
    let arr = [8, 9, 7, 5, 2, 4, 6, 1, 3];
    insertion(arr);
    console.log(arr)
}
