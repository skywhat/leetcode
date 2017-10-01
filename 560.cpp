#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
public:
	int subarraySum(vector<int>& nums,int k){
		unordered_map<int,int> m;
		int sum=0;
		m[0]=1;
		//take into account the sum from the nums[0] to nums[i]
		int cnt=0;
		for(int i=0;i<nums.size();++i){
			sum+=nums[i];
			cnt+=m[sum-k];
			m[sum]++;
		}
		return cnt;
	}
};

int main(){
	vector<int> nums={1,1,1};
	int k=2;

	Solution s;
	cout<<s.subarraySum(nums,k)<<endl;

	return 0;

}
