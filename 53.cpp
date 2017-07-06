#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		vector<int> sumArray(nums.size(), nums[0]);
		int minSum = min(0,sumArray[0]);
		int maxValue = nums[0];
		for (int i = 1; i < sumArray.size(); ++i) {
			sumArray[i] = sumArray[i - 1] + nums[i];
			maxValue = max(sumArray[i] - minSum, maxValue);
			minSum = min(sumArray[i], minSum);
		}
		return maxValue;
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