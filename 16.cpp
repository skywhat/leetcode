#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int threeSumClosest(vector<int>& nums,int target){
        sort(nums.begin(),nums.end());
        int dist=INT_MAX;
        int sum;
        int res;
        for(int i=0;i+2<nums.size();++i){
            int j=i+1,k=nums.size()-1;
            while(j<k){
                sum=nums[i]+nums[j]+nums[k];
                if(abs(sum-target)<dist){
                    dist=abs(sum-target);
                    res=sum;
                    if(!dist)
                    return res;
                }
                sum>target?k--:j++;
            }
        }
        return res;
    }
};

int main(){
	vector<int> test={-1,2,1,-4};
	int target=1;
	Solution s;
	cout<<s.threeSumClosest(test,target)<<endl;

	return 0;
}
