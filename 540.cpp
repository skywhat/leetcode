#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	int singleNonDuplicate(vector<int>& nums){
		int low=0,high=nums.size()/2,mid;
		while(low<high){
			mid=(low+high)/2;
			if(nums[2*mid]==nums[2*mid+1])
				low=mid+1;
			else
				high=mid;
		}
		return nums[2*low];
	}
};

int main(){
	vector<int> testcase={1,1,2,3,3,4,4,8,8};
	vector<int> testcase1={3,3,7,7,10,11,11};

	Solution s;
	cout<<s.singleNonDuplicate(testcase1)<<endl;

	return 0;
}
