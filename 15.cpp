#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> res;
        int n=nums.size();
        if(n<3)
            return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i+2<nums.size();++i){
            //nums[i-1]!=nums[i] no more duplicate triplets exists
            //nums[i]<=0 the first element in triplet is obviously less than or equal to 0
            if(nums[i]<=0&&(i==0||(i>0&&nums[i-1]!=nums[i]))){
                if(nums[i]+nums[i+1]+nums[i+2]>0)
                    break;
                if(nums[i]+nums[n-1]+nums[n-2]<0)
                    continue;
                int start=i+1,end=nums.size()-1;
                int sum=0-nums[i];
                while(start<end){
                    if(nums[start]+nums[end]>sum){
                        end--;
                    }
                    else if(nums[start]+nums[end]<sum){
                        start++;
                    }
                    else{
                        res.push_back({nums[i],nums[start],nums[end]});
                        int prev=nums[start];
                        while(start<end&&prev==nums[start])
                            start++;
                        prev=nums[end];
                        while(start<end&&prev==nums[end])
                            end--;
                    }
                }
            }
        }
        return res;
    }
};
//Your runtime beats 99.85 % of cpp submissions.

int main(){
    vector<int> test={-1,0,1,0};
    vector<int> test1={-1,0,1,2,-1,4};
    Solution s;
    vector<vector<int>> res=s.threeSum(test);
    for(auto row:res){
        cout<<"[";
        for(auto elem:row){
            cout<<elem<<", ";
        }
        cout<<"]"<<endl;
    }
    
    return 0;
}


/*
 *follow up:
 *three sum, which allows duplicates and each number could be used.
 *change three code snippet
 *
 * 1. i<nums.size()
 * 2. start=i
 * 3. start<=end
 *
 *follow up 2:
 *the array cannot be sorted
 *convert it to two sum problem.
 *
 *
 */
