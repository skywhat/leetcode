#include<iostream>
#include<vector>

using namespace std;

//Time Limit Exceeded.
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        if(target<0)
            return 0;
        if(target==0)
            return 1;
        int res=0;
        for(int i=0;i<nums.size();++i){
            res+=combinationSum4(nums,target-nums[i]);
        }
        return res;
    }
};

//dynamic programming
class Solution2 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,0);
        dp[0]=1;
        for(int i=1;i<=target;++i){
            for(int j=0;j<nums.size();++j){
                if(i-nums[j]>=0){
                    dp[i]+=dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};

int main(){
	vector<int> nums={1,2,3};
	int target=32;

	Solution s;
	cout<<s.combinationSum4(nums,target)<<endl;

	return 0;

}
