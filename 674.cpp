#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(!nums.size())
        return 0;
        int cnt=1;
        int maxLen=1;
        for(int i=1;i<nums.size();++i){
            if(nums[i]>nums[i-1])
            maxLen=max(++cnt,maxLen);
            else
            cnt=1;
        }
        return maxLen;
    }
};

int main(){
    vector<int> test={1,3,5,4,7};
    Solution s;
    cout<<s.findLengthOfLCIS(test)<<endl;
    
    return 0;
}
