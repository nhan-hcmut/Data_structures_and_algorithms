#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxNumberOfPeople(vector<int>& rooms, vector<int>& people, int k) {
    sort(rooms.begin(), rooms.end());
    sort(people.begin(), people.end());

    int room = 0, person = 0, count = 0;
    
    while (room < rooms.size() && person < people.size()) {
        if (rooms[room] >= people[person] - k && rooms[room] <= people[person] + k) {
            count++;
            room++;
            person++;
        }
        else if (rooms[room] < people[person] - k) {
            room++;
        }
        else {
            person++;
        }
    }
    return count;
}

int main() {
    
    // Test	1
    int peopleCount, roomCount, k;
    cin >> peopleCount >> roomCount >> k;
    
    vector<int> people(peopleCount);
    vector<int> rooms(roomCount);

    for (int i = 0; i < peopleCount; i++)
        cin >> people[i];
    for (int i = 0; i < roomCount; i++)
        cin >> rooms[i];
    cout << maxNumberOfPeople(rooms, people, k) << '\n';
    /* Input
    3 4 5
    30 60 75
    57 45 80 65
    
    Result: 2
    */

    /* Test	2
    int peopleCount, roomCount, k;
    cin >> peopleCount >> roomCount >> k;
    
    vector<int> people(peopleCount);
    vector<int> rooms(roomCount);

    for (int i = 0; i < peopleCount; i++)
        cin >> people[i];
    for (int i = 0; i < roomCount; i++)
        cin >> rooms[i];
    cout << maxNumberOfPeople(rooms, people, k) << '\n';
    
    Input:
    10 10 1000
    18 59 71 65 97 83 80 68 92 67
    59 5 65 15 42 81 58 96 50 1
    
    Result: 10
    */
    return 0;
}
