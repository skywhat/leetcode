#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

class Solution{
public:
	void bubblesort(vector<int>& nums){
		for(int i=0;i<=nums.size()-2;++i){
			for(int j=nums.size()-1;j>i;--j){
				if(nums[j]<nums[j-1])
					swap(nums[j],nums[j-1]);
			}
		}
	}
};

int main(){
	vector<int> testcase={3,2,6,8,9,5,4,1,0};
	Solution s;
	s.bubblesort(testcase);
	copy(testcase.begin(),testcase.end(),ostream_iterator<int>(cout,", "));
	cout<<endl;

	return 0;
}
