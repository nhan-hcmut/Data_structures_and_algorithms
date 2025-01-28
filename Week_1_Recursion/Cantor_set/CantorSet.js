/*
Print Cantor set by X(s) and spaces

E.g. a Cantor set with order = 3

XXXXXXXXX => line = 0, stop = 9. There are 9 Xs. 9 = 3^2 = three_power(order - 1 - line)
XXX   XXX => line = 1, stop = 3. There are 3 Xs. 3 = 3^1 = three_power(order - 1 - line)
X X   X X => line = 2, stop = 1. There is 1 X. 1 = 3^0 = three_power(order - 1 - line)
*/
let cantor_set = "";
let stop = -1; // A flag to stop the recursion

function three_power(n) { // 3 raised to the power of n
    if (n == 0) return 1;
    return 3 * three_power(n - 1);
}

function print_space(n) { // Print n spaces
    for (let i = 0; i < n; i++) {
        cantor_set += " ";
    }
}

function print_x(n) { // Print n X(s) recursively
    if (n == stop) {
        for (let i = 0; i < stop; i++) {
            cantor_set += "X";
        }
    }
    else {
        print_x(n / 3);
        print_space(n / 3);
        print_x(n / 3);
    }
}

let order = 4; // Order of Cantor set
console.log("Order = 4");

for (let line = 0; line < order; line++) {
    stop = three_power(order - 1 - line);
    
    print_x(three_power(order - 1));
    console.log(cantor_set);
    cantor_set = "";
}
