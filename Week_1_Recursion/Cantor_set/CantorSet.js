/*
Print Cantor set by X(s) and spaces

E.g. a Cantor set with order = 3

XXXXXXXXX => Line = 0. Stop = 9. There are 9 Xs. 9 = 3^2 = power(order-1-line)
XXX   XXX => Line = 1. Stop = 3. There are 3 Xs. 3 = 3^1 = power(order-1-line)
X X   X X => Line = 2. Stop = 1. There is 1 X. 1 = 3^0 = power(order-1-line)
*/
let cantor = "";
let stop = -1; // A flag to stop the recursion

function power(n) { // 3 raised to the power of n
    if (n == 0) {
        return 1;
    }
    return 3 * power(n-1);
}

function print_space(n) { // Just print n spaces
    for (let i=0; i<n; i++) {
        cantor += " ";
    }
}

function print_x(n) { // Print n X(s) recursively
    if (n == stop) {
        for (let i=0; i<stop; i++) {
            cantor += "X";
        }
    }
    else {
        print_x(n/3);
        print_space(n/3);
        print_x(n/3);
    }
}

let order = 4; // Order of Cantor set
console.log("Order = 4");

for (let line=0; line < order; line++) {
    stop = power(order-1-line);
    print_x(power(order-1));
    console.log(cantor);
    cantor = "";
}