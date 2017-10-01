#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
public:
	int findMaxLength(vector<int>& nums){
		unordered_map<int,int> m;
		int sum=0;
		int maxLen=0;
		m[0]=-1;
		for(int i=0;i<nums.size();++i){
			sum+=nums[i]==0?-1:1;
			auto it=m.find(sum);
			if(it!=m.end()){
				maxLen=max(maxLen,i-m[sum]);
			}
			else
				m[sum]=i;
		}
		return maxLen;
	}
};

int main(){
	vector<int> nums={0,0,0,0,1,1};
	Solution s;
	cout<<s.findMaxLength(nums)<<endl;

	return 0;

}

