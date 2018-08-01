#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
public:
	vector<int> twoSum(vector<int>& nums,int target){
		unordered_map<int,int> table;
		
		for(int i=0;i<nums.size();++i){
			if(table.find(target-nums[i])!=table.end()){
				return vector<int>{table[target-nums[i]], i};
			}
			else{
				table[nums[i]]=i;
			}
		}
		
        	return vector<int>();
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
