#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int,int> next_greater;
        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j){
                if(nums[j]>nums[i]){
                    next_greater[nums[i]]=nums[j];
                    break;
                }
            }
        }
        
        vector<int> res;
        for(int i=0;i<findNums.size();++i){
            res.push_back(
                next_greater.find(findNums[i]) == next_greater.end()? 
                -1: next_greater[findNums[i]]
            );
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int,int> next_greater;
        for(auto n: nums){
            while(s.size() && s.top()<n){
                next_greater[s.top()]=n;
                s.pop();
            }
            s.push(n);
        }
        
        vector<int> res;
        for(int i=0;i<findNums.size();++i){
            res.push_back(
                next_greater.count(findNums[i])?
                next_greater[findNums[i]] : -1
            );
        }
        
        return res;
    }
};

int main(){


