#include<iostream>
using namespace std;

void move(int n, string source, string destination, string auxiliary) {

    if (n == 1) {
        cout << "Move a disk from " << source << " to " << destination << endl;
    }
    else {
        move(n-1, source, auxiliary, destination);
        move(1, source, destination, auxiliary);
        move(n-1, auxiliary, destination, source);
    }
}

int main() {

    move(3, "left tower", "right tower", "middle tower");

    return 0;
}