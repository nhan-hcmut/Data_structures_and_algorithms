#include <iostream>
using namespace std;

int findGCD(int a, int b) {
    if (b == 0) return a;
    return findGCD(b, a%b);
}

int findLCM(int a, int b) {
    
    int GCD = findGCD(a, b);
    
    return a * b / GCD;
}

int main() {
    
    cout << findLCM(10, 102);

    return 0;
}
