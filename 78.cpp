#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	vector<vector<int>> subsets(vector<int>& nums){
		vector<vector<int>> res;
		subsets(res,nums,0,vector<int>());
		return res;

	}
	void subsets(vector<vector<int>>& res,vector<int>& nums,int pos,vector<int> temp){
		if(pos==nums.size()){
			res.push_back(temp);
			return;
		}
		subsets(res,nums,pos+1,temp);
		temp.push_back(nums[pos]);
		subsets(res,nums,pos+1,temp);
	}
};

int main(){
	vector<int> test={1,2,3};
	Solution s;
	auto res=s.subsets(test);
	for(auto row:res){
		cout<<"[";
		for(auto elem:row){
			cout<<elem<<", ";
		}
		cout<<"]"<<endl;
	}
	
	return 0;
}



