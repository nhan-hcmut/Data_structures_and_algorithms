/*
Print Cantor set by X(s) and spaces

E.g. a Cantor set with order = 3

XXXXXXXXX => line = 0, stop = 9. There are 9 Xs. 9 = 3^2 = three_power(order - 1 - line)
XXX   XXX => line = 1, stop = 3. There are 3 Xs. 3 = 3^1 = three_power(order - 1 - line)
X X   X X => line = 2, stop = 1. There is 1 X. 1 = 3^0 = three_power(order - 1 - line)
*/
#include<iostream>
using namespace std;

int stop; // A flag to stop the recursion

int three_power(int n) { // 3 raised to the power of n
    if (n == 0) return 1;
    return 3 * three_power(n - 1);
}

void print_space(int n) { // Print n spaces
    for (int i = 0; i < n; i++) {
        cout << " ";
    }
}

void print_x(int n) { // Print n X(s) recursively
    if (n == stop) {
        for (int i = 0; i < stop; i++) {
            cout << "X";
        }
    }
    else {
        print_x(n / 3);
        print_space(n / 3);
        print_x(n / 3);
    }
}

int main() {

    int order = 0; // Order of Cantor set

    while (order < 1 || 5 < order) {
        cout << "Order (from 1 to 5): ";
        cin >> order;
    }

    for (int line = 0; line < order; line++) {
        stop = three_power(order - line - 1);
        print_x(three_power(order - 1));
        cout << endl;
    }

    return 0;
}
