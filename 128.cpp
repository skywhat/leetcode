#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen=0;
        unordered_set<int> s(nums.begin(),nums.end());
        for(auto n:s){
            if(!s.count(n-1)){
                int cnt=1;
                while(s.count(n+cnt)){
                    cnt++;
                }
                maxLen=max(maxLen,cnt);
            }
        }
        return maxLen;
    }
};

int main(){
    
}
