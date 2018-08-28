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
            copy(heights.begin(), heights.end(),
                 ostream_iterator<int>(cout, ", "));
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

int main() {}
