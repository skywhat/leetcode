// Given two sparse matrices A and B, return the result of AB.
//
// You may assume that A's column number is equal to B's row number.
//
// Example:
//
// Input:
//
// A = [
//   [ 1, 0, 0],
//   [-1, 0, 3]
// ]
//
// B = [
//   [ 7, 0, 0 ],
//   [ 0, 0, 0 ],
//   [ 0, 0, 1 ]
// ]
//
// Output:
//
//      |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
// AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
//                   | 0 0 1 |

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A,
                                 vector<vector<int>>& B) {
        int m = A.size();
        int mn = A[0].size();
        int n = B[0].size();

        vector<vector<int>> res(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int k = 0; k < mn; ++k) {
                if (A[i][k] == 0) {
                    continue;
                }
                for (int j = 0; j < n; ++j) {
                    res[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        return res;
    }
};

int main() {}
