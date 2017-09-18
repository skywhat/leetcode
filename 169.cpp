#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution{
public:
	int majorityElement(vector<int>& nums){
		int majority=nums[0],count=1;
		for(int i=1;i<nums.size();++i){
			if(nums[i]==majority)
				count++;
			else{
				if(count==0){
					majority=nums[i];
					count++;
				}
				else
					count--;
			}
		}
		return majority;
	}
};

class Solution2{
public:
	int majorityElement(vector<int>& nums){
		int limit=nums.size()/2;
		unordered_map<int,int> m;
		for(auto n:nums){
			if(++m[n]>limit)
				return n;
		}
	}
};
	
int main(){
	vector<int> nums={1,2,3,3,3,2,3};
	Solution s;
	cout<<s.majorityElement(nums)<<endl;

	return 0;
}
