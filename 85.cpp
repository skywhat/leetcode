/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (!m) {
            return 0;
        }
        int n = matrix[0].size();
        vector<int> heights(n + 1, 0);
        int max_area = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                } else {
                    heights[j]++;
                }
            }
            max_area = max(max_area, maxHistArea(heights));
        }

        return max_area;
    }

    int maxHistArea(const vector<int>& heights) {
        stack<int> index;
        int max_area = 0;

        int i = 0;
        while (i < heights.size()) {
            if (index.empty() || heights[index.top()] <= heights[i]) {
                index.push(i);
                i++;
            } else {
                int h = heights[index.top()];
                index.pop();
                int left_index = index.empty() ? -1 : index.top();
                max_area = max(max_area, h * (i - left_index - 1));
            }
        }

        return max_area;
    }
};

class Solution2 {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (!m) {
            return 0;
        }
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        vector<int> left(n, 0);
        vector<int> right(n, n);
        int max_area = 0;

        for (int i = 0; i < m; ++i) {
            int cur_left = 0, cur_right = n;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                    left[j] = 0;
                    cur_left = j + 1;
                } else {
                    heights[j]++;
                    left[j] = max(left[j], cur_left);
                }
            }
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '0') {
                    right[j] = n;
                    cur_right = j;
                } else {
                    right[j] = min(right[j], cur_right);
                }
            }

            for (int j = 0; j < n; ++j) {
                max_area = max(max_area, heights[j] * (right[j] - left[j]));
            }
        }

        return max_area;
    }
};

int main() {}
