/*
Given an array nums of n integers where n > 1,  return an array output such that
output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not
count as extra space for the purpose of space complexity analysis.)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        int prod = 1;
        for (int i = 1; i < n; ++i) {
            prod = prod * nums[i - 1];
            res[i] = prod;
        }

        prod = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            res[i] = res[i] * prod;
            prod = prod * nums[i];
        }

        return res;
    }
};

/*
1 2 3 4
1 1 1 1
1 1 2 6

tmp=4
1 1 2 6
1 1 8 6
tmp=4*3=12
1 12 8 6

tmp=4*3*2=24
24 12 8 6


*/

int main() {}
