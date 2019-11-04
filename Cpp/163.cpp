#include<iostream>
#include<string>
#include<vector>

using namespace std;


class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        long prev,curr;
        for(int i=0;i<=nums.size();++i){
            prev=i==0?lower:(long)nums[i-1]+1;
            curr=i==nums.size()?upper:(long)nums[i]-1;
            if(prev==curr){
                res.push_back(to_string(prev));
            }
            else if(prev<curr){
                res.push_back(to_string(prev)+"->"+to_string(curr));
            }
        }
        return res;
    }
};
