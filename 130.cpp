#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size()==0)
            return;
        int m=board.size();
        int n=board[0].size();
        
        for(int i=0;i<m;++i){
            flipToN(board,i,0);
            flipToN(board,i,n-1);
        }
        for(int j=0;j<n;++j){
            flipToN(board,0,j);
            flipToN(board,m-1,j);
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]=='N')
                    board[i][j]='O';
            }
        }
    }
    void flipToN(vector<vector<char>>& board,int i,int j){
        if(board[i][j]=='O'){
            board[i][j]='N';
            if(i-1>=0)
                flipToN(board,i-1,j);
            if(i+1<board.size())
                flipToN(board,i+1,j);
            if(j-1>=0)
                flipToN(board,i,j-1);
            if(j+1<board[0].size())
                flipToN(board,i,j+1);
        }
    }
};

int main(){
    
}
