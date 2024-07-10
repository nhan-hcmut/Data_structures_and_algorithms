#include<iostream>
using namespace std;

void move(int n, string source, string destination, string auxiliary) {
    static int step = 0;
    
    if (n == 1) {
        cout << "Step " << ++step << ": Move a disk from " << source << " to " << destination << endl;
    }
    else {
        move(n-1, source, auxiliary, destination);
        move(1, source, destination, auxiliary);
        move(n-1, auxiliary, destination, source);
    }
}

int main() {

    int disk = 0;

    while (disk < 1) {
        cout << "Disk (>=1): ";
        cin >> disk;
    }

    move(disk, "left tower", "right tower", "middle tower");

    return 0;
}
