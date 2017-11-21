#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==0)
        return -1;
        if(n==1)
        return nums[0]==target?0:-1;
        
        if(nums[0]<nums[n-1])
        return binarySearch(nums,0,n-1,target);
        int pt=find(nums);
        if(target>=nums[0])
        return binarySearch(nums,0,pt,target);
        else
        return binarySearch(nums,pt+1,n-1,target);
        
    }
    int binarySearch(vector<int>& nums,int left,int right,int target){
        while(left+1<right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target)
            return mid;
            else if(nums[mid]>target)
            right=mid-1;
            else
            left=mid+1;
        }
        if(nums[left]==target)
        return left;
        else if(nums[right]==target)
        return right;
        else
        return -1;
    }
    int find(vector<int>& nums){
        int i=0,j=nums.size()-1;
        while(i+1<j){
            int mid=i+(j-i)/2;
            if(nums[mid]>nums[mid+1]&&nums[mid]>nums[mid-1])
            return mid;
            else if(nums[mid]<nums[0])
            j=mid;
            else
            i=mid;
        }
        if(nums[i]>nums[j])
        return i;
        else
        return j;
    }
};

int main(){

}
