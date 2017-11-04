#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size()==0)
            return res;
        int up=0,down=matrix.size()-1;
        int left=0,right=matrix[0].size()-1;
        while(left<=right&&up<=down){
            for(int i=left;i<=right;++i){
                res.push_back(matrix[up][i]);
            }
            up++;
            for(int i=up;left<=right&&i<=down;++i){
                res.push_back(matrix[i][right]);
            }
            right--;
            for(int i=right;up<=down&&i>=left;--i){
                res.push_back(matrix[down][i]);
            }
            down--;
            for(int i=down;left<=right&&i>=up;--i){
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};

int main(){
}
