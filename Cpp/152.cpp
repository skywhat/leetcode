#include<iostream>
#include<vector>

using namespace std;

/*
 
 if there is only one negative number, nums[i]
 the maximum product must be nums[0]*nums[1]*...nums[i-1] or nums[i+1]*nums[i+2]*...nums[n-1]
 
 if there are two negative number, obviously the maximum product would be nums[0]*nums[1]*...nums[n-1]
 
 Just like this, we can store two variables front and back to record the product from left to right, or from right to left respectively.
 
 */
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int front=1;
        int back=1;
        int n=nums.size();
        int res=nums[0];
        for(int i=0;i<nums.size();++i){
            front*=nums[i];
            back*=nums[n-i-1];
            res=max(res,max(front,back));
            if(front==0)
                front=1;
            if(back==0)
                back=1;
        }
        return res;
    }
};

int main(){
}
