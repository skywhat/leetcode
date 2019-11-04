// Given an array with n objects colored red, white or blue, sort them in-place
// so that objects of the same color are adjacent, with the colors in the order
// red, white and blue.
//
// Here, we will use the integers 0, 1, and 2 to represent the color red, white,
// and blue respectively.
//
// Note: You are not suppose to use the library's sort function for this
// problem.
//
// Example:
//
// Input: [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
// Follow up:
//
// A rather straight forward solution is a two-pass algorithm using counting
// sort. First, iterate the array counting number of 0's, 1's, and 2's, then
// overwrite array with total number of 0's, then 1's and followed by 2's. Could
// you come up with a one-pass algorithm using only constant space?

#include <iostream>
#include <vector>

using namespace std;

// two-pass algorithm using counting sort
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> color(3, 0);
        for (auto n : nums) {
            color[n]++;
        }

        int i = 0, j = 0;
        while (i < 3) {
            while (color[i]--) {
                nums[j++] = i;
            }
            i++;
        }
    }
};

// one pass algorithm
class Solution2 {
public:
    void sortColors(vector<int>& nums) {
        int red = 0, blue = nums.size() - 1;
        int i = 0;
        while (i <= blue) {
            if (nums[i] == 0) {
                swap(nums[i], nums[red++]);
            } else if (nums[i] == 2) {
                swap(nums[i--], nums[blue--]);
            }
            i++;
        }
    }
};

int main() {
    vector<int> color = {1, 0, 1, 2, 0, 0, 2, 2};
    Solution s;
    s.sortColors(color);

    for (auto c : color)
        cout << c << ", ";
    cout << endl;

    return 0;
}
