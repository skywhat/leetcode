#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dir = {-3, 3, -1, 1};
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        string start = convertTostring(board);

        string target = "123456780";
        set<string> visit = {start, ""};
        int move = 0;
        queue<string> q;
        q.push(start);

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string cur = q.front();
                q.pop();
                if (cur == target) {
                    return move;
                }

                int i = cur.find('0');
                for (auto d : dir) {
                    int j = d + i;
                    string next = moveTonext(i, j, cur, m, n);

                    if (visit.find(next) == visit.end()) {
                        visit.insert(next);
                        q.push(next);
                    }
                }
            }
            move++;
        }

        return -1;
    }

    string convertTostring(vector<vector<int>>& board) {
        string start;
        for (auto row : board) {
            for (auto c : row) {
                start += '0' + c;
            }
        }
        return start;
    }

    string moveTonext(int i, int j, string cur, int m, int n) {
        if (j < 0 || j >= m * n) {
            return "";
        }
        for (int x = 1; x < m; ++x) {
            if ((i == n * x && j == n * x - 1)
                || (i == n * x - 1 && j == n * x)) {
                return "";
            }
        }

        swap(cur[i], cur[j]);
        return cur;
    }
};

int main() {
    vector<vector<int>> board = {
        {1, 6, 2},
        {7, 0, 3},
        {5, 4, 8},
    };

    Solution s;
    cout << s.slidingPuzzle(board) << endl;

    return 0;
}
