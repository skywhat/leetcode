#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	int threeSumSmaller(vector<int>& nums,int target){
		sort(nums.begin(),nums.end());
		int sum=0;
		for(int i=0;i+2<nums.size();++i){
			int j=i+1,k=nums.size()-1;
			while(j<k){
				if(nums[i]+nums[j]+nums[k]<target){
					sum+=k-j;
					j++;
				}
				else
					k--;
			}
		}
		return sum;
	}
};

int main(){
	vector<int> test={-2,0,1,3};
	int target=2;
	Solution s;
	cout<<s.threeSumSmaller(test,target)<<endl;

	return 0;
}
