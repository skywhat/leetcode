#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int min_sum = min(0, nums[0]);
        int cur_sum = nums[0];
        int max_subsum = nums[0];
        for(int i=1;i<nums.size();++i){
            cur_sum += nums[i];
            max_subsum = max(max_subsum, cur_sum-min_sum);
            min_sum = min(min_sum, cur_sum);
        }
        
        return max_subsum;
    }
};

int main() {
	vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
	vector<int> nums1 = {1,2};
	vector<int> nums2 = { -2,1 };
	Solution s;
	cout << s.maxSubArray(nums2) << endl;

	return 0;
}
