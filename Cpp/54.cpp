/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the
matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (!m) {
            return {};
        }
        int n = matrix[0].size();
        int left = 0, right = n - 1;
        int top = 0, bottom = m - 1;
        vector<int> res;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right && top <= bottom; ++i) {
                res.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i <= bottom && left <= right; ++i) {
                res.push_back(matrix[i][right]);
            }
            right--;
            for (int i = right; i >= left && top <= bottom; --i) {
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
            for (int i = bottom; i >= top && left <= right; --i) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }

        return res;
    }
};

int main() {}
