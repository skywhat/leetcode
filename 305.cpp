#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> uf(m * n, -1);
        vector<int> res;
        int cnt = 0;

        for (auto p : positions) {
            cnt++;
            int cur = p.first * n + p.second;
            uf[cur] = cur;

            for (auto d : dir) {
                int x = p.first + d[0];
                int y = p.second + d[1];
                int nb = x * n + y;
                if (x < 0 || x >= m || y < 0 || y >= n || uf[nb] == -1) {
                    continue;
                }

                int cur_root = find(uf, cur);
                int nb_root = find(uf, nb);
                if (cur_root != nb_root) {
                    cnt--;
                    uf[nb_root] = cur_root;
                }
            }

            res.push_back(cnt);
        }

        return res;
    }

    int find(vector<int>& uf, int id) {
        while (uf[id] != id) {
            uf[id] = uf[uf[id]]; // path compression
            id = uf[id];
        }

        return id;
    }
};

int main() {}
