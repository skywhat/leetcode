#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		bool used_row[9][9] = { false };
		bool used_col[9][9] = { false };
		bool used_subBox[9][9] = { false };
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					int index = board[i][j] - '1';
					int k = (i / 3) * 3 + j / 3;
					if (used_row[i][index] || used_col[j][index] || used_subBox[k][index])
						return false;
					used_row[i][index] = used_col[j][index] = used_subBox[k][index] = true;
				}
			}
		}
		return true;
	}
};

class Solution_1 {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<bool> valid(10, false);
		for (int i = 0; i < 9; ++i) {
			fill(valid.begin(), valid.end(), false);
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					if (valid[board[i][j] - '0'])
						return false;
					valid[board[i][j] - '0'] = true;
				}
			}
		}

		for (int i = 0; i < 9; ++i) {
			fill(valid.begin(), valid.end(), false);
			for (int j = 0; j < 9; ++j) {
				if (board[j][i] != '.') {
					if (valid[board[j][i] - '0'])
						return false;
					valid[board[j][i] - '0'] = true;
				}
			}
		}

		vector<int> region = { 0,1,2,3,4,5,6,7,8 };
		for (auto r : region) {
			fill(valid.begin(), valid.end(), false);
			for (int i = (r / 3) * 3; i < (r / 3) * 3 + 3; ++i) {
				for (int j = (r % 3) * 3; j < (r % 3) * 3 + 3; ++j) {
					if (board[i][j] != '.') {
						if (valid[board[i][j] - '0'])
							return false;
						valid[board[i][j] - '0'] = true;
					}
				}
			}
		}

		return true;
	}
};

int main() {

}