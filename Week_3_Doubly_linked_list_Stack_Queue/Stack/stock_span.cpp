#include<iostream>
#include<vector>
using namespace std;

vector<int> stock_span(const vector<int>& ns) {
    // STUDENT ANSWER
    vector<int> result = {1};
    int size = ns.size();
    
    for (int i = 1; i < size; i++) {
        if (ns[i] <= ns[i-1]) result.push_back(1);
        else {
            int count = 1;
            for (int j = i - 1; j >= 0 && ns[j] < ns[i]; j--) count++;
            result.push_back(count);
        }
    }
    return result;
}

int main() {

    // test 1
    vector<int> ns = {100, 80, 60, 70, 60, 75, 85};
    vector<int> span = stock_span(ns);
    for (int i = 0; i < span.size(); i++) cout << span[i] << ' '; // Result: 1 1 1 2 1 4 6

    /* test 2
    vector<int> ns = {10, 4, 5, 90, 120, 80};
    vector<int> span = stock_span(ns);
    for (int i = 0; i < span.size(); i++) cout << span[i] << ' '; // Result: 1 1 2 4 5 1
    */
    return 0;
}
