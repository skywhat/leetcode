/*
 * Selection sort is to repetitively pick up the smallest element and put it into the right position:
 * .Find the smallest element, and put it to the first position.
 * .Find the next smallest element, and put it to the second position.
 * .Repeat until all elements are in the right positions.
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	void SelectionSort(vector<int>& nums){
		for(int i=0;i+1<nums.size();++i){
			int minId=i;
			for(int j=i+1;j<nums.size();++j){
				if(nums[j]<nums[minId])
					minId=j;
			}
			swap(nums[i],nums[minId]);
		}
	}
};

int main(){
	vector<int> nums={5,1,9,2,4,3,8,7,6};
	Solution s;
	s.SelectionSort(nums);

	for(auto n:nums){
		cout<<n<<", ";
	}
	cout<<endl;

}
