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
        if(!n)
            return false;
        int i=0,j=n-1;
        while(i<m&&j>=0){
            if(matrix[i][j]==target)
                return true;
            else if(matrix[i][j]<target)
                i++;
            else
                j--;
        }
        return false;
    }
};

int main(){

}
