#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution{
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0;i+2<nums.size();++i){
            //nums[i-1]!=nums[i] no more duplicate triplets exists
            //nums[i]<=0 the first element in triplet is obviously less than or equal to 0
            if((!i||(i>0&&nums[i-1]!=nums[i]))&&(nums[i]<=0)){
                int start=i+1,end=nums.size()-1;
                int sum=0-nums[i];
                while(start<end){
                    if(nums[start]+nums[end]>sum){
                        int prev=nums[end];
                        while(prev==nums[end])
                            end--;
                    }
                    else if(nums[start]+nums[end]<sum){
                        int prev=nums[start];
                        while(prev==nums[start])
                            start++;
                    }
                    else{
                        vector<int> temp={nums[i],nums[start],nums[end]};
                        res.push_back(temp);
                        int prev=nums[start];
                        while(prev==nums[start])
                            start++;
                        while(nums[end-1]==nums[end])
                            end--;
                    }
                }
            }
        }
        return res;
    }
};

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
