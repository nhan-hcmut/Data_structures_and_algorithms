#include <iostream>
using namespace std;

// Helping functions
string findFirstWord(string str, int len, int index = 0) {

    if (index >= len) return "";

    if (str[index] != ' ') return str[index] + findFirstWord(str, len, index+1);

    return "";
}
// End helping functions

string reverseSentence(string s) {

    string firstWord = findFirstWord(s, s.length());

    if (firstWord.length()+1 >= s.length()) return firstWord;
    
    return reverseSentence(s.substr(firstWord.length()+1, s.length()-firstWord.length()-1)) + " " + firstWord;
}

int main() {
    cout << reverseSentence("data structure and algorithm is scary") << endl;

    cout << reverseSentence("data structures and algorithms is challenging") << endl;

    return 0;
}
