/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down.
 You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int longestIncreasingPath(vector<vector<int>>& matrix) {
		if (matrix.empty())
			return 0;
		int maxPath = 0;
		vector<vector<int>> flag(matrix.size(),vector<int>(matrix[0].size()));
		for (int i = 0; i < matrix.size(); ++i) {
			for (int j = 0; j < matrix[0].size(); ++j) {
				int cnt=find(matrix,i,j,flag);
				if (cnt > maxPath)
					maxPath = cnt;
			}
		}
		return maxPath;
	}
	int find(vector<vector<int>>& matrix,int row,int col,vector<vector<int>>& flag) {
		if (flag[row][col] != 0)
			return flag[row][col];
		int maxPath = 1;
		for (auto d : dir) {
			int x = row + d[0], y = col + d[1];
			if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size()||matrix[x][y]<=matrix[row][col])
				continue;
			int res = 1+find(matrix,x,y,flag);
			if (res > maxPath)
				maxPath=res;
		}
		flag[row][col] = maxPath;
		return maxPath;
	}
private:
	vector<vector<int>> dir = { {0,1},{0,-1},{1,0},{-1,0} };
};

int main() {
	Solution s;
	vector<vector<int>> nums1 = {
		{9,9,4},
		{6,6,8},
		{2,1,1}
	};
	vector<vector<int>> nums2 = {
		{3,4,5},
		{3,2,6},
		{2,2,1}
	};
	vector<vector<int>> nums3 = {
		{7,7,5},
		{2,4,6},
		{8,2,0}
	};
	vector<vector<int>> nums4 = {
		{3,3,3},
		{3,3,3},
		{3,3,3}
	};
	int maxPath = s.longestIncreasingPath(nums3);

	cout << maxPath << endl;

	return 0;
}

