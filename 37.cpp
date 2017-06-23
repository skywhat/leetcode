#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		solve(board);
	}

	bool solve(vector<vector<char>>& board) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] == '.') {
					for (char c = '1'; c <= '9'; ++c) {
						if (isValid(board, i, j, c)) {
							board[i][j] = c;
							if (solve(board))
								return true;
							else
								board[i][j] = '.';
						}
					}
					return false;
				}
			}
		}
		return true;
	}

	bool isValid(const vector<vector<char>>& board, int i, int j, char c) {
		for (int index = 0; index < 9; ++index) {
			if (board[index][j] == c)
				return false;
			if (board[i][index] == c)
				return false;
			if (board[i / 3 * 3 + index / 3][j / 3 * 3 + index % 3] == c)
				return false;
		}
		return true;
	}
};

int main() {
	string sudoku = "..9748...7.........2.1.9.....7...24..64.1.59..98...3.....8.3.2.........6...2759..";
	vector<vector<char>> v;
	for (int i = 0; i < 9; ++i) {
		vector<char> tmp(sudoku.begin() + i * 9, sudoku.begin() + i * 9 + 9);
		v.push_back(tmp);
	}
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

	Solution s;
	s.solveSudoku(v);
	cout << "AFTER SOLVE SUDOKU:" << endl;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}

	return 0;

}