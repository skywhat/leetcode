#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
public:
	vector<int> twoSum(vector<int>& nums,int target){
		unordered_map<int,int> m;
		vector<int> res;
		for(int i=0;i<nums.size();++i){
			if(m.find(target-nums[i])!=m.end()){
				res.push_back(m[target-nums[i]]);
				res.push_back(i);
				return res;
			}
			else{
				m[nums[i]]=i;
			}
		}
		return res;
	}

};

int main(){
	vector<int> testcase={2,7,11,15};
	int target=9;
	Solution s;
	vector<int> res=s.twoSum(testcase,target);
	for(int i=0;i<res.size();++i){
		cout<<res[i]<<", ";
	}
	cout<<endl;

	return 0;
}
