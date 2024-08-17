#include<iostream>
#include<vector>
using namespace std;

int longestSublist(vector<string>& words) {
    // STUDENT ANSWER
    if (words.empty()) return 0;
    int size = words.size(), max = 0, temp = 0;
    for (int i = 0; i < size; i++) {
        temp = 0;
        for (int k = i; k < size; k++) {
            if (words[k][0] == words[i][0]) temp++;
            else break;
		}
        max = max > temp ? max : temp;
    }
    return max;
}

int main() {

    // test 1
    vector<string> words {"faction", "fight", "and", "are", "attitude"};
    cout << longestSublist(words); // Result: 3
    
    /* test 2
    vector<string> words {};
    cout << longestSublist(words); // result: 0
    */

    /* test 3
    vector<string> words {"also", "and", "an", "currying", "and", "day", "and", "and", "constituent", "an"};
    cout << longestSublist(words); // result: 3
    */
    
    /* test 4
    vector<string> words {"and", "earth", "boating", "a", "are", "and", "and", "and", "as", "capulet", "and", "families", "central", "for", "and", "and", "central", "and", "ant", "fluids"};
    cout << longestSublist(words); // result: 6
    */

    /* test 5
    vector<string> words {"by", "cousin", "application", "count", "constituent", "chorus", "fight", "each", "an", "daughter", "and", "disguise", "boats", "concept", "and", "cousin", "cooling", "boat", "application", "for", "and", "banish", "family", "and", "fight", "also", "as", "but", "family", "cooking", "currying", "and", "fight", "faction", "apple", "and", "colorless", "feast", "as", "feuding", "and", "falls", "and", "by", "an", "a", "and", "chemical", "agree", "and", "are", "falls", "are", "and", "a", "and", "capulets", "and", "as", "are", "and", "currying", "cousin", "each", "colorless", "entertainment", "and", "an", "fight", "agree", "ant", "after", "and", "a", "accept", "and", "colorless", "and", "another", "day", "chemical", "and", "are", "an", "diving", "faction", "chemical", "constituent", "banish", "concept", "and", "attitude", "as", "ant", "capulet", "as", "and", "application", "entertainment", "agressive"};
    cout << longestSublist(words); // result: 7
    */

    /* test 6
    vector<string> words {"application", "boats", "fight", "and", "a", "at", "fishing", "and", "as", "both", "application", "and", "application", "and", "attitude", "are", "entertainment", "an", "as", "as", "discover", "canals", "another", "capulet", "an", "currying", "also", "boats", "colorless", "and", "apple", "as", "composed", "both", "concept", "and", "entertainment", "agree", "a", "for", "a", "application", "count", "chorus", "apple", "and", "composed", "and", "after", "capulets", "at", "boating", "feast", "daughter", "cooling", "families", "boats", "and", "a", "by", "begins", "at", "apple", "apple", "boating", "but", "fluids", "another", "boat", "each", "as", "are", "and", "at", "another", "are", "and", "and", "benvolio", "all", "discover", "a", "capulets", "a", "agree", "capulets", "application", "are", "cooking", "and", "and", "beloved", "boys", "an", "excellent", "daughter", "application", "and", "each", "and", "and", "are", "and", "currying", "each", "capulet", "entertainment", "are", "ant", "currying", "for", "but", "ant", "attitude", "and", "and", "boat", "and", "at", "colorless", "but", "ant", "and", "cooking", "also", "at", "at", "discover", "also", "beloved", "chemical", "and", "daughter", "beloved", "banish", "currying", "boating", "colorless", "and", "constituent", "families", "disguise", "concept", "and", "an", "a", "and", "disguise", "and", "currying", "accept", "are", "families", "as", "all", "family", "composed", "an", "and", "an", "day", "and", "and", "and", "and", "and", "after", "a", "daughter", "and", "boating", "are", "feuding", "fluids", "apple", "boys", "agree", "ant", "and", "and", "boating", "begins", "currying", "and", "but", "a", "family", "currying", "entertainment", "for", "and", "an", "and", "discover", "and", "boating", "a", "constituent", "constituent", "as", "application", "and", "families", "feuding", "excellent", "apple", "currying", "and", "beloved", "concept", "boat", "currying", "and", "chorus", "boat", "are", "and", "canals", "application", "are", "an", "are", "beloved", "composed", "application", "begins", "agree", "composed", "and", "after", "at", "and", "and", "boating", "and", "central", "chorus", "and", "an", "are", "begins", "and", "falls", "are", "begins", "and", "and", "fight", "for", "application", "a", "each", "and", "a", "and", "discover", "also", "and", "for", "and", "and", "earth", "falls", "as", "boat", "fluids", "attitude", "boat", "are", "family", "accept", "chemical", "and", "and", "as", "and", "families", "composed", "application", "and", "a", "and", "all", "another", "and", "cousin", "and", "beloved", "for", "are", "entertainment", "and", "families", "discover", "cooling", "currying", "and", "are", "colorless", "boating", "after", "an", "a", "cooling", "and", "both", "composed", "feast", "begins", "both", "currying", "entertainment", "a", "by", "a", "both", "by", "and", "as", "are", "currying", "and", "and", "family", "attitude", "currying", "beloved", "falls", "are", "a", "and", "boating", "are", "discover", "and", "currying", "diving", "and", "fight", "agressive", "family", "canals", "a", "boats", "and", "and", "agressive", "and", "cousin", "also", "benvolio", "feuding", "and", "composed", "all", "and", "cooling", "a", "feast", "are", "are", "and", "are", "an", "and", "as", "and", "begins", "apple", "capulets", "and", "capulets", "families", "boating", "boats", "and", "earth", "and", "are", "amper", "currying", "amper", "begins", "currying", "at", "are", "also", "discover", "daughter", "are", "and", "as", "but", "and", "as", "boat", "cooking", "for", "after", "currying", "and", "beloved", "faction", "application", "also", "day", "diving", "and", "and", "families", "agree", "and", "central", "and", "constituent", "daughter", "are", "chorus", "discover", "and", "and", "cooking", "and", "ant", "family", "also", "fluids", "benvolio", "and", "fluids", "falls", "both", "boating", "a", "a", "each", "and", "and", "and", "as", "discover", "after", "and", "and", "all", "day", "and", "and", "application", "are", "excellent", "and", "and", "as", "faction", "and", "as", "boating", "discover", "also", "are", "chorus", "excellent", "an", "at", "daughter", "are", "and", "and", "currying", "and", "day", "discover", "and", "agree", "and", "apple", "and", "and", "are", "cooling", "and", "boat", "discover", "and", "beloved", "diving", "and", "after", "family", "an", "an", "each", "and", "fight", "families", "and", "by", "and", "and"};
    cout << longestSublist(words); // result: 8
    */

    return 0;
}
