#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> help(nums.size(),false);
        int last=nums.size()-1;
        for(int i=nums.size()-1;i>=0;--i){
            if(nums[i]>=last-i){
                help[i]=true;
                last=i;
            }
        }
        return help[0];
    }
};

int main(){
    vector<int> test={3,2,1,0,4};
    Solution s;
    cout<<s.canJump(test)<<endl;
    
    return 0;
}
