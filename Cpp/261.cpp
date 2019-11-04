#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> uf(n, -1);

        for (int i = 0; i < edges.size(); ++i) {
            int v1 = find(uf, edges[i].first);
            int v2 = find(uf, edges[i].second);
            if (v1 == v2) {
                return false;
            }

            uf[v1] = v2;
        }

        return edges.size() == n - 1;
    }
    int find(const vector<int>& uf, int id) {
        if (uf[id] == -1) {
            return id;
        }

        return find(uf, uf[id]);
    }
};

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> uf(n, 0);
        for (int i = 0; i < n; ++i) {
            uf[i] = i;
        }

        for (auto&& e : edges) {
            int v1 = find(uf, e.first);
            int v2 = find(uf, e.second);
            if (v1 == v2) {
                return false;
            }

            uf[v1] = v2;
        }

        return edges.size() == n - 1;
    }

    int find(vector<int>& uf, int id) {
        while (uf[id] != id) {
            uf[id] = uf[uf[id]];
            id = uf[id];
        }

        return id;
    }
};
int main() {}
