#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)
            return false;
        int a=INT_MAX;
        int b=INT_MAX;
        for(int i=0;i<nums.size();++i){
            if(nums[i]<=a)//a is the minimum one so far
                a=nums[i];
            else if(nums[i]<=b)//b is the second minimum one so fat
                b=nums[i];
            else
                return true;// find one larger than a and b
        }
        return false;
    }
};

int main(){

}
