#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	int removeDuplicates(vector<int>& nums){
		if(nums.size()==0)
			return 0;
		int start=0;
		for(int i=0;i<nums.size();++i){
			if(nums[start]!=nums[i]){
				start++;
				nums[start]=nums[i];
			}
		}
		return start+1;
	}
};

int main(){
	vector<int> testcase={1,1,2};
	Solution s;
	int length=s.removeDuplicates(testcase);
	for(int i=0;i<length;++i){
		cout<<testcase[i]<<", ";
	}
	cout<<endl;
	return 0;
}
