// Given a positive integer n, generate a square matrix filled with elements
// from 1 to n2 in spiral order.
//
// Example:
//
// Input: 3
// Output:
// [
//  [ 1, 2, 3 ],
//  [ 8, 9, 4 ],
//  [ 7, 6, 5 ]
// ]

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;
        int val = 1;

        while (left <= right && top <= bottom) {
            for (int i = left; i <= right && top <= bottom; ++i) {
                res[top][i] = val++;
            }
            top++;

            for (int i = top; i <= bottom && left <= right; ++i) {
                res[i][right] = val++;
            }
            right--;

            for (int i = right; i >= left && top <= bottom; --i) {
                res[bottom][i] = val++;
            }
            bottom--;

            for (int i = bottom; i >= top && left <= right; --i) {
                res[i][left] = val++;
            }
            left++;
        }

        return res;
    }
};
