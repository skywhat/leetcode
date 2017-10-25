/*
 Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
 
 For example, given the following matrix:
 
 1 0 1 0 0
 1 0 1 1 1
 1 1 1 1 1
 1 0 0 1 0
 Return 4.
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        int max_width=0;
        for(int i=0;i<m;++i){
            dp[i][0]=matrix[i][0]-'0';
            max_width=max(max_width,dp[i][0]);
        }
        for(int j=1;j<n;++j){
            dp[0][j]=matrix[0][j]-'0';
            max_width=max(max_width,dp[0][j]);
        }
        for(int i=1;i<m;++i){
            for(int j=1;j<n;++j){
                if(matrix[i][j]=='1'){
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]))+1;
                    max_width=max(max_width,dp[i][j]);
                }
            }
        }
        return max_width*max_width;
    }
};


class Solution2 {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(!m)
            return 0;
        int n=matrix[0].size();
        vector<int> prev(m,0);
        vector<int> cur(m,0);
        int max_width=0;
        for(int i=0;i<m;++i){
            prev[i]=matrix[i][0]-'0';
            max_width=max(max_width,prev[i]);
        }
        for(int j=1;j<n;++j){
            cur[0]=matrix[0][j]-'0';
            max_width=max(max_width,cur[0]);
            for(int i=1;i<m;++i){
                if(matrix[i][j]=='1'){
                    cur[i]=min(cur[i-1],min(prev[i],prev[i-1]))+1;
                    max_width=max(max_width,cur[i]);
                }
                else{
                    cur[i]=0;
                }
            }
            for(int i=0;i<m;++i)
                prev[i]=cur[i];
        }
        return max_width*max_width;
    }
};
