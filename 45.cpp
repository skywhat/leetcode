#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	int jump(vector<int>& nums){
		int step=0;
		int maxDist=0;
		int next=0;
		int last=nums.size()-1;
		for(int i=0;i<last;++i){
			maxDist=max(maxDist,i+nums[i]);
			if(i==next){
				step++;
				next=maxDist;
			}
			if(maxDist>=last&&next<last)
				return step+1;
			else if(maxDist>=last&&next>=last)
				return step;
		}
		return step;
	}
};

int main(){
	vector<int> test={2,3,1,1,4};

	Solution s;
	cout<<s.jump(test)<<endl;

	return 0;
}



