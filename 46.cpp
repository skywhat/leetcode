#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
	vector<vector<int>> permute(vector<int>& nums){
		vector<vector<int>> res;
		permute(res,nums,0);
		return res;
	}

	void permute(vector<vector<int>>& res,vector<int> &nums,int start){
		if(start+1==nums.size()){
			res.push_back(nums);
		}
		else{
			for(int i=start;i<nums.size();++i){
				swap(nums[i],nums[start]);
				permute(res,nums,start+1);
				swap(nums[i],nums[start]);
			}
		}
	}
};

int main(){
	vector<int> test={1,2,3,4};
	Solution s;
	vector<vector<int>> res=s.permute(test);
	for(auto row:res){
		cout<<"[";
		for(auto elem:row){
			cout<<elem<<", ";
		}
		cout<<"]"<<endl;
	}

	return 0;
}
