#include<iostream>
#include<vector>

using namespace std;

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

int main(){
	vector<int> nums={1,2,3};
	int target=32;

	Solution s;
	cout<<s.combinationSum4(nums,target)<<endl;

	return 0;

}
