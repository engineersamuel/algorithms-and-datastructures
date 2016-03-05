"use strict";

function shell(arr) {
    let gap = Math.floor(arr.length / 2);
    while (gap >= 1) {

        for (let i = 0; i < arr.length - gap; i++) {
            let pos = i + gap;
            while (pos - gap >= 0 && arr[pos] < arr[pos - gap]) {
                // This doesn't seem to work yet despite destructuring set
                //[arr[pos], arr[pos - gap]] = [arr[pos - gap], arr[pos]];
                const temp = arr[pos];
                arr[pos] = arr[pos - gap];
                arr[pos - gap] = temp;
                pos -= gap;
            }
        }
        gap = Math.floor(gap / 2);
    }
}

if (require.main === module) {
    console.log("Shell sort");
    let arr = [8, 9, 7, 5, 2, 4, 6, 1, 3];
    shell(arr);
    console.log(arr);
}
