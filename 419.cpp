#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	int countBattleships(vector<vector<char>>& board){
		if(board.size()==0)
			return 0;
		int res=0;
		for(int i=0;i<board.size();++i){
			for(int j=0;j<board[0].size();++j){
				if(board[i][j]=='X'){
					res++;
					board[i][j]='.';
					flip(board,i,j);
				}
			}
		}	
		return res;
	}
	
	void flip(vector<vector<char>>& board,int row,int col){
		for(int i=row+1;i<board.size();++i){
			if(board[i][col]=='X')
				board[i][col]='.';
			else
				break;
		}
		for(int j=col+1;j<board[0].size();++j){
			if(board[row][j]=='X')
				board[row][j]='.';
			else
				break;
		}
	}
};

class Solution2{
public:
	int countBattleships(vector<vector<char>>& board){
		if(board.size()==0)
			return 0;
		int res=0;
		for(int i=0;i<board.size();++i){
			for(int j=0;j<board[0].size();++j){
				if(board[i][j]=='.')
					continue;
				if(i>0&&board[i-1][j]=='X')
					continue;
				if(j>0&&board[i][j-1]=='X')
					continue;
				res++;
			}
		}
		return res;
	}
};

int main(){
	vector<vector<char>> test={
		{'X','.','.','X'},
		{'.','.','.','X'},
		{'.','.','.','X'}
	};	
	vector<vector<char>> test1={
		{'X','X','X'}
	};

	for(auto row:test){
		for(auto elem:row)
			cout<<elem;
		cout<<endl;
	}
	Solution s;
	cout<<s.countBattleships(test1)<<endl;

	return 0;

}




