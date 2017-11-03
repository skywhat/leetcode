#include<iostream>
#include<vector>

using namespace std;

/*
 
 Here is my idea: instead of calculating area by height*width, we can think it in a cumulative way. In other words, sum water amount of each bin(width=1).
 Search from left to right and maintain a max height of left and right separately, which is like a one-side wall of partial container. Fix the higher one and flow water from the lower part. For example, if current height of left is lower, we fill water in the left bin. Until left meets right, we filled the whole container.
 
 */

class Solution {
public:
    int trap(vector<int>& height) {
        int i=0,j=height.size()-1;
        int left=0,right=0;
        int res=0;
        while(i<=j){
            left=max(height[i],left);
            right=max(height[j],right);
            if(left<=right){
                res+=left-height[i];
                i++;
            }
            else{
                res+=right-height[j];
                j--;
            }
        }
        return res;
    }
};


int main(){

}
