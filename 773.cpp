// On a 2x3 board, there are 5 tiles represented by the integers 1 through 5,
// and an empty square represented by 0.
//
// A move consists of choosing 0 and a 4-directionally adjacent number and
// swapping it.
//
// The state of the board is solved if and only if the board is
// [[1,2,3],[4,5,0]].
//
// Given a puzzle board, return the least number of moves required so that the
// state of the board is solved. If it is impossible for the state of the board
// to be solved, return -1.
//
// Examples:
//
// Input: board = [[1,2,3],[4,0,5]]
// Output: 1
// Explanation: Swap the 0 and the 5 in one move.
// Input: board = [[1,2,3],[5,4,0]]
// Output: -1
// Explanation: No number of moves will make the board solved.
// Input: board = [[4,1,2],[5,0,3]]
// Output: 5
// Explanation: 5 is the smallest number of moves that solves the board.
// An example path:
// After move 0: [[4,1,2],[5,0,3]]
// After move 1: [[4,1,2],[0,5,3]]
// After move 2: [[0,1,2],[4,5,3]]
// After move 3: [[1,0,2],[4,5,3]]
// After move 4: [[1,2,0],[4,5,3]]
// After move 5: [[1,2,3],[4,5,0]]
// Input: board = [[3,2,4],[1,5,0]]
// Output: 14
// Note:
//
// board will be a 2 x 3 array as described above.
// board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5]

class Solution {
public:
    vector<int> dir = {-1, 1, -3, 3};

    int slidingPuzzle(vector<vector<int>>& board) {
        string start;
        for (auto row : board) {
            for (auto c : row) {
                start += c + '0';
            }
        }
        string target = "123450";
        set<string> s;
        s.insert(start);
        queue<string> q;
        q.push(start);
        int move = 0;

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
                    int j = i + d;
                    if (j < 0 || j > 5 || (i == 2 && j == 3)
                        || (i == 3 && j == 2)) {
                        continue;
                    }
                    string next = cur;
                    swap(next[i], next[j]);
                    if (!s.count(next)) {
                        s.insert(next);
                        q.push(next);
                    }
                }
            }
            move++;
        }

        return -1;
    }
};

class Solution2 {
public:
    vector<int> dir = {-3, 3, -1, 1};
    int slidingPuzzle(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        string start = convertTostring(board);

        string target = "123450";
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
