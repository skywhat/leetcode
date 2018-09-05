/*
Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down.
 You may NOT move diagonally or move outside of the boundary (i.e. wrap-around
is not allowed).

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

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (!m) {
            return 0;
        }
        int n = matrix[0].size();
        vector<vector<int>> cache(m, vector<int>(n));

        int longest = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int len = find(matrix, cache, i, j);
                longest = max(longest, len);
            }
        }

        return longest;
    }

    int find(vector<vector<int>>& matrix,
             vector<vector<int>>& cache,
             int i,
             int j) {
        if (cache[i][j] != 0) {
            return cache[i][j];
        }

        int len = 1;
        for (auto d : dir) {
            int x = i + d[0];
            int y = j + d[1];
            if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size()
                || matrix[i][j] >= matrix[x][y]) {
                continue;
            }
            len = max(len, 1 + find(matrix, cache, x, y));
        }
        cache[i][j] = len;
        return len;
    }

private:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
};

int main() {
    Solution s;
    vector<vector<int>> nums1 = {{9, 9, 4}, {6, 6, 8}, {2, 1, 1}};
    vector<vector<int>> nums2 = {{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};
    vector<vector<int>> nums3 = {{7, 7, 5}, {2, 4, 6}, {8, 2, 0}};
    vector<vector<int>> nums4 = {{3, 3, 3}, {3, 3, 3}, {3, 3, 3}};
    int maxPath = s.longestIncreasingPath(nums3);

    cout << maxPath << endl;

    return 0;
}
