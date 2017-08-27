/*
The eight queens puzzle is the problem of placing eight chess queens on
an 8×8 chessboard so that no two queens threaten each other.
Thus, a solution requires that no two queens share the same row, column, or diagonal.
The eight queens puzzle is an example of the more general
n queens problem of placing n non-attacking queens on an n×n chessboard, 
for which solutions exist for all natural numbers n with the exception of n=2 and n=3.[1]
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	//默认为4皇后
	Solution(int _n=4):n(_n),pos(_n,-1) {}

	vector<int> pos;
	//count 计数
	int count = 0;
	// n为皇后数
	int n;

	// 非递归算法
	void NQueenIterate() {
		int row = 0;
		while (row >= 0) {
			pos[row]++;
			while (pos[row] < n && (!isPlace(row)))
				pos[row]++;
			if (pos[row] < n) {
				if (row < n - 1) {
					row++;
					pos[row] = -1;
				}
				else {
					count++;
					print();
				}
			}
			else
				row--;
		}
	}

	//递归算法
	void NQueenRecurse(int row) {
		pos[row] = -1;
		while (1) {
			pos[row]++;
			while (pos[row] < n && !isPlace(row))
				pos[row]++;
			if (pos[row] < n) {
				if (row < n - 1)
					NQueenRecurse(row + 1);
				else {
					count++;
					print();
				}
			}
			else
				return;
		}
	}

	//如果两个Queen在同一列，或者斜对角，不满足条件，返回false
	bool isPlace(int row) {
		for (int i = 0; i < row; ++i) {
			if (pos[i] == pos[row] || abs(pos[i] - pos[row]) == abs(i - row))
				return false;
		}
		return true;
	}
	void print() {
		cout << "Solution " << count <<" :"<< endl;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j)
				if (j != pos[i])
					cout << "X ";
				else
					cout << "Q ";
			cout << endl;
		}
		cout << endl;
	}
};

int main() {
	Solution s(8);

	//s.NQueenIterate();
	s.NQueenRecurse(0);
	cout << s.count << endl;
	return 0;
}