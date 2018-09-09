class Solution {
private:
    vector<vector<int>> skip;

public:
    Solution() {
        skip.assign(10, vector<int>(10, 0));
        skip[1][3] = skip[3][1] = 2;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[7][9] = skip[9][7] = 8;
        skip[2][8] = skip[8][2] = skip[4][6] = skip[6][4] = skip[1][9]
            = skip[9][1] = skip[3][7] = skip[7][3] = 5;
    }

    int numberOfPatterns(int m, int n) {
        int res = 0;
        vector<bool> visit(10, false);
        for (int i = m; i <= n; ++i) {
            res += dfs(visit, 1, i - 1) * 4;
            res += dfs(visit, 2, i - 1) * 4;
            res += dfs(visit, 5, i - 1);
        }

        return res;
    }

    int dfs(vector<bool> visit, int start, int remaining) {
        if (remaining == 0) {
            return 1;
        }

        int res = 0;
        visit[start] = true;
        for (int i = 1; i <= 9; ++i) {
            if (visit[i]) {
                continue;
            }
            if (skip[start][i] == 0 || visit[skip[start][i]]) {
                res += dfs(visit, i, remaining - 1);
            }
        }

        return res;
    }
};
