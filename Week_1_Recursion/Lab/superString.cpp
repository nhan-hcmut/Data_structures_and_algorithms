#include <iostream>
#include <string>
using namespace std;

int superString(string x, string y, int m, int n) {
    
    if (m == 0) return n; // If m = 0, string x is empty -> superstring of x and y is y
    
    if (n == 0) return m; // If n = 0, string y is empty -> superstring of x and y is x
    
    if (x.at(m - 1) == y.at(n - 1)) return superString(x, y, m - 1, n - 1) + 1; // If the last character of x and y are the same, result will be one plus the length of the shortest superstring of 2 substrings. The first substring is the first m-1 characters of x and the second substring is the first n-1 characters of y
    
    return min(superString(x, y, m, n - 1), superString(x, y, m - 1, n)) + 1; // If the last character of x and y are not the same, result will be one plus the length of the shortest superstring of 2 strings. Those 2 strings can be x and the first n-1 characters of y or the first m-1 characters of x and y, depend on whose shortest superstring is shorter
}

int main() {
    // Test 1
    string x = "ABCBDAB";
    string y = "BDCABA";
    int m = x.length(), n = y.length();
    cout << superString(x, y, m, n) << "\n"; // result: 9

    // Test 2
    // string x = "abcde";
    // string y = "efghijkl";
    // int m = x.length(), n = y.length();
    // cout << superString(x, y, m, n) << "\n"; // result: 12

    return 0;
}