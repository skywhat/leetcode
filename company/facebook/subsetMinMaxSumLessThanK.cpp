#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Solution{
public:
	int subsetMinMaxSum(vector<int>& nums,int k){
		int i=0,j=nums.size()-1;
		int res=0;
		//if k>0 add empty subset
		if(k)
			res++;
		while(i<=j){
			if(nums[i]+nums[j]>=k){
				j--;
			}
			else{
				//all the subset which has the minimal value nums[i]
				res+=pow(2,j-i);
				i++;
			}
		}
		return res;
	}

};


int main(){
	vector<int> nums={1,2,3,4,5};
	int k=5;
	Solution s;
	cout<<s.subsetMinMaxSum(nums,k)<<endl;

	cout<<endl;
}



