#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if(nums.size()<2){
            return nums.size();
        }
        
        int max_len = 1;
        int cnt = 1;
        
        for(int i=1;i<nums.size();++i){
            if(nums[i] > nums[i-1]){
                max_len = max(max_len, ++cnt);
            }
            else{
                cnt = 1;
            }
        }
        
        return max_len;
    }
};

int main(){
    vector<int> test={1,3,5,4,7};
    Solution s;
    cout<<s.findLengthOfLCIS(test)<<endl;
    
    return 0;
}
