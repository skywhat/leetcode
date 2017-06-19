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

int main() {
	Solution s;
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

