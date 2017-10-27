/*
https://leetcode.com/problems/word-search/#/description



Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell,
 where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/


#include<iostream>
#include<vector>
#include<string>
#include<set>


using namespace std;

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int row_size = board.size();
		int col_size = board[0].size();
		for (int i = 0; i < row_size; ++i) {
			for (int j = 0; j < col_size; ++j) {
				if (exist(board, word, i, j, 0))
					return true;
			}
		}
		return false;
	}
	bool exist(vector<vector<char>>& board, const string& word, int row,int col,int pos) {
		if (pos == word.size())
			return true;
		else if (board[row][col]=='*'||board[row][col] != word[pos])
			return false;
		else {
			char tmp = board[row][col];
			board[row][col] = '*';
			if (
				(row - 1 >= 0 && exist(board, word, row - 1, col, pos + 1)) ||
				(row + 1 < board.size() && exist(board, word, row + 1, col, pos + 1)) ||
				(col + 1 < board[0].size() && exist(board, word, row, col + 1, pos + 1)) ||
				(col - 1 >= 0 && exist(board, word, row, col - 1, pos + 1))
				)
				return true;
			board[row][col] = tmp;
			return false;
		}
	}
};

class Solution2 {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool res=false;
        int m=board.size();
        int n=board[0].size();
        set<pair<int,int>> help;
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(board[i][j]==word[0]){
                    if(find(board,word,0,i,j,m,n,help))
                        return true;
                }
            }
        }
        return false;
    }
    bool find(vector<vector<char>>& board,const string& word,int pos,int x,int y,const int& m,const int& n,set<pair<int,int>>& s){
        if(pos+1==word.size()){
            return word[pos]==board[x][y]&&!s.count({x,y});
        }
        if(board[x][y]!=word[pos]||s.count({x,y}))
            return false;
        s.insert({x,y});
        if(
           (x+1<m&&find(board,word,pos+1,x+1,y,m,n,s))||
           (x-1>=0&&find(board,word,pos+1,x-1,y,m,n,s))||
           (y+1<n&&find(board,word,pos+1,x,y+1,m,n,s))||
           (y-1>=0&&find(board,word,pos+1,x,y-1,m,n,s))
           )return true;
        s.erase({x,y});
        return false;
    }
};

int main() {
	Solution2 s;
	vector<vector<char>> t = { {'h','e','l','l','o'} };
	/*
	vector<vector<char>> v = {
		{"ABCE"},
		{"SFCS"},
		{"ADEE" },
		{"ABCCED"}
	};
	*/
	string word = "lleh";
	cout << s.exist(t, word);

	return 0;
}

