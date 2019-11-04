#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	int removeDuplicates(vector<int>& nums){
		if(nums.size()==0)
			return 0;
		int count=1,start=1;
		for(int i=1;i<nums.size();++i){
			if(nums[i]!=nums[i-1]){
				nums[start]=nums[i];
				start++;
				count=1;
			}
			//change 2 to k, then duplicates are allowed at most k times.
			else if(count<2){
				nums[start]=nums[i];
				count++;
				start++;
			}
		}
		return start;
	}
};

int main(){
	vector<int> test={1,1,2,2,2,2,3,4,4,4,5};
	Solution s;
	int len=s.removeDuplicates(test);
	for(int i=0;i<len;++i)
		cout<<test[i]<<", ";
	cout<<endl;

	return 0;
}
