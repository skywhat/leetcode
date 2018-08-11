#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i+1<j){
            int mid = i+(j-i)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] < target){
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        
        if(nums[i] >= target){
            return i;
        }
        
        return j;
    }
};

/*

1 3 5 6     target=2
0 1 2 3

i=0,j=3,m=1
i=0,j=1

[1,3,5,6]
 0 1 2 3
7

*/

int main(){

}
