#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
public:
	bool checkSubarraySum(vector<int>& nums,int k){
		if(nums.size()<=1)
			return false;
		if(k==0){
			for(int i=1;i<nums.size();++i)
				if(nums[i-1]==0&&nums[i]==0)
					return true;
			return false;
		}
		unordered_map<int,int> m;
		int sum=0;
		for(int i=0;i<nums.size();++i){
			sum+=nums[i];
			if(sum%k==0&&i>0)
				return true;
			else if(m[sum%k]==0)
				m[sum%k]=i+1;
			//i+1 but not i since the default value of non-exist key is 0
			else if(i-m[sum%k]>0)
				return true;
		}
		return false;
	}
};

int main(){
	vector<int> test={23,2,4,6,7};
	int k=-6;

	Solution s;
	cout<<s.checkSubarraySum(test,k)<<endl;

	return 0;
}
