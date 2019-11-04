#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

class Solution{
public:
	vector<vector<int>> permuteUnique(vector<int>& nums){
		vector<vector<int>> res;
		permute(res,nums,0);
		return res;

	}
	void permute(vector<vector<int>>& s,vector<int>& nums,int start){
		if(start+1==nums.size()){
			s.push_back(nums);
		}
		else{
			for(int i=start;i<nums.size();++i){
				if(i!=start&&nums[i]==nums[start])
					continue;
				swap(nums[i],nums[start]);
				permute(s,nums,start+1);
				swap(nums[i],nums[start]);
			}
		}
	}
};
int main(){
	vector<int> test={1,1,2};
	Solution s;
	vector<vector<int>> res=s.permuteUnique(test);

	for(auto row:res){
		cout<<"[";
		for(auto elem:row){
			cout<<elem<<", ";
		}
		cout<<"]"<<endl;
	}

	return 0;
}
