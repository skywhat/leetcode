// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as
// one sorted array.
//
// Note:
//
// The number of elements initialized in nums1 and nums2 are m and n
// respectively. You may assume that nums1 has enough space (size that is
// greater or equal to m + n) to hold additional elements from nums2. Example:
//
// Input:
// nums1 = [1,2,3,0,0,0], m = 3
// nums2 = [2,5,6],       n = 3
//
// Output: [1,2,2,3,5,6]

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j])
                i++;
            else {
                nums1.insert(nums1.begin() + i, nums2[j++]);
                m++;
                i++;
            }
        }

        for (; j < n; ++j, ++m) {
            nums1.insert(nums1.begin() + m, nums2[j]);
        }
        nums1.erase(nums1.begin() + m, nums1.end());
    }
};

class Solution2 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    vector<int> nums1 = {0};
    int m = 0;
    vector<int> nums2 = {1};
    int n = 1;
    Solution s;
    s.merge(nums1, m, nums2, n);
    copy(nums1.begin(), nums1.end(), ostream_iterator<int>(cout, ", "));

    return 0;
}
