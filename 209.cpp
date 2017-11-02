#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution{
public:
	int minSubArrayLen(int s,vector<int>& nums){
		if(nums.size()==0)
			return 0;
		int i=0,j=0;
		int minLen=INT_MAX;
		int sum=0;
		while(j<nums.size()){
			sum+=nums[j++];
			while(sum>=s){
				minLen=min(minLen,j-i);
				sum-=nums[i++];
			}
		}	
		return minLen==INT_MAX?0:minLen;
	}
};

//easy to understand
class Solution2 {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int sum=0;
        int minLen=INT_MAX;
        for(int i=0,j=-1;i<nums.size();++i){
            sum+=nums[i];
            while(sum>=s){
                minLen=min(minLen,i-j);
                j++;
                sum-=nums[j];
            }
        }
        return minLen==INT_MAX?0:minLen;
    }
};

int main(){
	vector<int> arr={2,3,1,2,4,3};
	int len=7;
	Solution s;
	cout<<s.minSubArrayLen(len,arr)<<endl;

	return 0;
}


