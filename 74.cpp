#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(!m)
            return false;
        int n=matrix[0].size();
        int size=m*n;
        int left=0,right=size-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            int val=matrix[mid/n][mid%n];
            if(val==target)
                return true;
            else if(val>target)
                right=mid-1;
            else
                left=mid+1;
        }
        return false;
    }
};
/*
0 1 2 3
4 5 6 7
8 9 10 11
[10/4][10%4]
*/

int main(){

}
