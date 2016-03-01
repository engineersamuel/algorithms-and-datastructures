"use strict";

function gcd_rec(x, y) {
    if (x == y) return x;
    return x > y ? gcd_rec(x - y, y) : gcd_rec(y, x);
}

function gcd_rec_mod(x, y) {
    if (y == 0) return x;
    return x > y ? gcd_rec_mod(y, x % y) : gcd_rec(y, x);
}

function gcd_itr_while(x, y) {
    if (x > y) return gcd_itr_while(y, x);
    while (y != 0) {
        [x, y] = [y, x % y];
    }
    return x;
}


if (require.main === module) {
    console.log(`25,15: ${gcd_rec(25, 15)}`);
    console.log(`15,25: ${gcd_rec(15, 25)}`);
    console.log(`25,15: ${gcd_rec_mod(25, 15)}`);
    console.log(`15,25: ${gcd_rec_mod(15, 25)}`);
    console.log(`25,15: ${gcd_itr_while(25, 15)}`);
    console.log(`15,25: ${gcd_itr_while(15, 25)}`);
}

