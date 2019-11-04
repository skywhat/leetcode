#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>

using namespace std;

//time O(nlgn) space O(1)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();++i)
            if(nums[i]==nums[i-1])
                return true;
        return false;
    }
};

//time O(n) space O(n)
class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        return nums.size() > s.size();
    }
};

//time O(n) space O(n)
class Solution3 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto n:nums){
            if(++m[n]>=2)
                return true;
        }
        return false;
    }
};

int main(){
}
