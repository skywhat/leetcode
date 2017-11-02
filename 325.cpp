#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0]=-1;
        int sum=0;
        int maxLen=0;
        for(int i=0;i<nums.size();++i){
            sum+=nums[i];
            auto it=m.find(sum-k);
            if(it!=m.end()){
                maxLen=max(maxLen,i-m[sum-k]);
            }
            if(!m.count(sum))
                m[sum]=i;
        }
        return maxLen;
    }
};

int main(){

}
