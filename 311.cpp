#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m=A.size(),n=A[0].size(),nb=B[0].size();
        vector<vector<int>> C(m,vector<int>(nb,0));
        for(int i=0;i<m;++i){
            for(int k=0;k<n;++k){
                if(A[i][k]!=0){
                    for(int j=0;j<nb;++j){
                        if(B[k][j]!=0)
                        C[i][j]+=A[i][k]*B[k][j];
                    }
                }
            }
        }
        return C;
    }
};

int main(){

}
