// Given two arrays, write a function to compute their intersection.
//
// Example 1:
//
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]
// Example 2:
//
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Note:
//
// Each element in the result should appear as many times as it shows in both
// arrays. The result can be in any order. Follow up:
//
// What if the given array is already sorted? How would you optimize your
// algorithm? What if nums1's size is small compared to nums2's size? Which
// algorithm is better? What if elements of nums2 are stored on disk, and the
// memory is limited such that you cannot load all elements into the memory at
// once?

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Time: O(m+n) Space: O(m+n)
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;

        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i++;
                j++;
            } else if (nums1[i] < nums2[j]) {
                i++;
            } else {
                j++;
            }
        }

        return res;
    }
};

// Time: O(max(m, n) log(max(m, n))) Space: O(m + n)
class Solution2 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dict;
        vector<int> res;
        for (auto n : nums1) {
            dict[n]++;
        }

        for (auto n : nums2) {
            if (--dict[n] >= 0) {
                res.push_back(n);
            }
        }

        return res;
    }
};

int main() {

    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    Solution s;
    vector<int> res = s.intersect(nums1, nums2);

    for (auto r : res)
        cout << r << ", ";
    cout << endl;

    return 0;
}
