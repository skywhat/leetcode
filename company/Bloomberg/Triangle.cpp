// Given a triangle, find the minimum path sum from top to bottom. Each step you
// may move to adjacent numbers on the row below.
//
// For example, given the following triangle
//
// [
//      [2],
//     [3,4],
//    [6,5,7],
//   [4,1,8,3]
// ]
// The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (!n) {
            return 0;
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                triangle[i][j]
                    += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        return triangle[0][0];
    }
};

// follow up
// [2,3,4,6,5,7,4,1,8,3]

class Solution2 {
public:
    int minimumTotal(vector<int> row) {
        int n = 1;
        int sum = 1;
        while (sum < row.size()) {
            n++;
            sum += n;
        }

        int i = row.size() - n - (n - 1);
        n--;
        while (i >= 0) {
            for (int j = 0; j < n; ++j) {
                int ind = i + j;
                if (row[ind + n + 1] < row[ind + n]) {
                    row[ind] += row[ind + n + 1];
                } else {
                    row[ind] += row[ind + n];
                }
            }
            n--;
            i -= n;
        }

        return row[0];
    }
};

int main() {
    Solution2 s;
    vector<int> test = {2, 3, 4, 6, 5, 7, 4, 1, 8, 3};
    cout << s.minimumTotal(test) << endl;

    return 0;
}
