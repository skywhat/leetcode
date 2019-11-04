class Solution {
public:
    bool hasPath(vector<vector<int>>& maze,
                 vector<int>& start,
                 vector<int>& destination) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == start[0] && j == start[1]) {
                    if (dfs(maze, visit, i, j, destination)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    bool dfs(vector<vector<int>>& maze,
             vector<vector<bool>>& visit,
             int i,
             int j,
             vector<int>& destination) {
        if (i == destination[0] && j == destination[1]) {
            return true;
        }

        visit[i][j] = true;
        for (auto d : dir) {
            int x = i + d[0];
            int y = j + d[1];

            while (x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size()
                   && !maze[x][y]) {
                if (visit[x][y]) {
                    break;
                }

                int next_x = x + d[0];
                int next_y = y + d[1];

                if (next_x < 0 || next_x >= maze.size() || next_y < 0
                    || next_y >= maze[0].size() || maze[next_x][next_y] == 1) {
                    if (dfs(maze, visit, x, y, destination)) {
                        return true;
                    }
                }

                x = next_x;
                y = next_y;
            }
        }

        return false;
    }
};
