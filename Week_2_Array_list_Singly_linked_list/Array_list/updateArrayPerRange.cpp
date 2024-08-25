#include<iostream>
#include<vector>
using namespace std;

vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations) {
    // STUDENT ANSWER
    short step = operations.size();
    for (short i = 0; i < step; i++) {
        for (short j = operations.at(i).at(0); j <= operations.at(i).at(1); j++) {
            nums[j] += operations.at(i).at(2);
        }
    }
    return nums;
}

void printVector(vector<int> nums) {
    short size = nums.size();
    cout << '[' << nums.at(0);
    for (short i = 1; i < size; i++) cout << ", " << nums.at(i);
    cout << "]\n";
}

int main() {
    
    // Test 1
    vector<int> nums {13, 0, 6, 9, 14, 16};
    vector<vector<int>> operations {{5, 5, 16}, {3, 4, 0}, {0, 2, 8}};
    printVector(updateArrayPerRange(nums, operations)); // Result: [21, 8, 14, 9, 14, 32]

    /* Test 2
    vector<int> nums {19, 4, 3, 2, 16, 3, 17, 8, 18, 12};
    vector<vector<int>> operations {{0, 3, 4}, {2, 5, 12}, {3, 6, 6}, {5, 8, 5}, {8, 9, 8}, {0, 5, 9}, {1, 7, 8}, {1, 1, 3}, {5, 5, 18}};
    printVector(updateArrayPerRange(nums, operations)); // Result: [32, 28, 36, 41, 51, 61, 36, 21, 31, 20]
    */

    /* Test 3
    vector<int> nums {4, 1, 3, 8, 9, 17, 8, 14, 10, 3, 3, 5, 4, 10, 13, 13, 12, 14, 12, 10};
    vector<vector<int>> operations {{10, 12, 7}, {0, 5, 18}};
    printVector(updateArrayPerRange(nums, operations)); // Result: [22, 19, 21, 26, 27, 35, 8, 14, 10, 3, 10, 12, 11, 10, 13, 13, 12, 14, 12, 10]
    */

    /* test 4
    vector<int> nums {11, 7, 19, 14, 14, 13, 10, 6, 2, 17, 1, 18, 14, 17, 3, 13, 15, 5, 7, 4, 14, 5, 15, 5, 13, 11, 11, 3, 10, 0, 15, 8, 8, 16, 7, 15, 18, 11, 2, 7, 1, 19, 1, 15, 2, 0, 5, 0, 9, 15, 15, 8, 16, 3, 3, 8, 11, 19, 0, 13, 15, 19, 19, 6, 13, 9, 9, 16, 8, 7, 9, 6, 19, 4, 1, 19, 12, 7, 4, 3, 7, 6, 14, 17, 15, 14, 19, 10, 18, 18, 9, 5, 16, 15, 15, 0, 6, 11, 18, 7};
    vector<vector<int>> operations {{24, 55, 19}, {23, 62, 9}, {39, 44, 12}, {45, 74, 1}, {67, 69, 7}, {23, 47, 14}, {33, 59, 4}, {33, 47, 7}, {85, 90, 10}, {10, 82, 5}, {63, 94, 19}, {27, 33, 14}, {82, 85, 5}, {2, 64, 7}, {53, 55, 13}, {50, 71, 19}, {9, 90, 6}, {8, 54, 0}, {33, 84, 16}, {44, 73, 11}, {9, 62, 16}, {34, 56, 6}, {20, 65, 10}, {18, 71, 2}, {27, 98, 16}, {32, 90, 11}, {67, 93, 18}, {18, 69, 14}, {27, 71, 18}, {22, 66, 18}, {67, 78, 12}, {18, 66, 10}, {42, 98, 15}, {10, 73, 4}, {27, 36, 16}, {39, 94, 1}, {43, 54, 1}, {47, 96, 15}, {13, 27, 0}, {33, 63, 17}, {76, 95, 4}, {25, 95, 19}, {45, 72, 6}};
    printVector(updateArrayPerRange(nums, operations)); // Result: [11, 7, 26, 21, 21, 20, 17, 13, 9, 46, 39, 56, 52, 55, 41, 51, 53, 43, 71, 68, 88, 79, 107, 120, 147, 164, 164, 220, 227, 217, 232, 225, 236, 288, 271, 279, 282, 259, 250, 268, 262, 280, 277, 292, 290, 283, 288, 298, 286, 292, 311, 304, 312, 312, 312, 316, 287, 289, 270, 283, 281, 285, 285, 266, 256, 245, 235, 251, 243, 242, 223, 220, 194, 173, 155, 172, 169, 164, 161, 148, 152, 151, 164, 162, 160, 153, 153, 144, 152, 152, 143, 112, 123, 122, 104, 69, 52, 42, 49, 7]
    */
    
    return 0;
}
