#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	int findPeakElement(vector<int>& nums){
		int left=0,right=nums.size()-1;
		while(left<right-1){
			int mid=(left+right)/2;
			if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])
				return mid;
			else if(nums[mid]<nums[mid-1])
				right=mid-1;
			else
				left=mid+1;
		}
		return nums[left]>nums[right]?left:right;
	}
};

int main(){
	vector<int> v={-2147483648,-2147483647};
	Solution s;
	cout<<s.findPeakElement(v)<<endl;

	return 0;
}
