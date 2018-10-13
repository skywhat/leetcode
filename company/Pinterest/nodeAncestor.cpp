// 1   2    3
// \  /    /  \
//   4    5    6
//    \  /  \    \
//     7    8    9
// 上面的node是下面的node的parent, 以edge的方式給, e.g.
// 上圖=[(1,4),(2,4),(4,7),(3,5),(5,7),(5,8),(3,6),(6,9)]，不考慮cycle
// 找nodes that have no parents, and nodes that have 1 parent
// [
//   [1,2,3],
//   [5,6,8,9],
// ]
// 2. 找graph中兩個node有無common ancestor (自己不算自己的ancestor, so input =
// (2,4), return false)
// e.g.
// (4,7) => true (common ancestor = 1)
// (7,8) => true
// (1,4) => false
// 3. 找furthest ancestor from node, return any one of the furthest parents,
// return -1 if node has no parent.
// e.g.
// 7=>1, 2 or 3
// 1=>-1
// 8=>3.

#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
    map<int, set<int>> prev;
    set<int> all;
    Solution(vector<vector<int>> input) {
        for (auto edge : input) {
            all.insert(edge.begin(), edge.end());
            prev[edge[1]].insert(edge[0]);
        }
    }

    vector<vector<int>> findParents() {
        vector<vector<int>> res(2, vector<int>());
        for (auto e : all) {
            if (prev[e].empty()) {
                res[0].push_back(e);
            } else if (prev[e].size() == 1) {
                res[1].push_back(e);
            }
        }

        return res;
    }

    bool hasCommonAncestor(int a, int b) {

        set<int> aparents;
        getAllParents(a, aparents);
        set<int> bparents;
        getAllParents(b, bparents);

        for (auto a_p : aparents) {
            if (bparents.count(a_p)) {
                return true;
            }
        }

        return false;
    }

    void getAllParents(int node, set<int>& parents) {
        for (auto p : prev[node]) {
            parents.insert(p);
            getAllParents(p, parents);
        }
    }

    void findFurthestParent(int node, pair<int, int>& parent, int step) {
        if (step > parent.second) {
            parent.first = node;
            parent.second = step;
        }
        for (auto next : prev[node]) {
            findFurthestParent(next, parent, step + 1);
        }
    }
};

int main() {
    vector<vector<int>> input
        = {{1, 4}, {2, 4}, {4, 7}, {3, 5}, {5, 7}, {5, 8}, {3, 6}, {6, 9}};
    Solution s(input);

    auto parents = s.findParents();
    cout << "indegree 0: ";
    for (auto p : parents[0]) {
        cout << p << ", ";
    }
    cout << endl;
    cout << "indegree 1: ";
    for (auto p : parents[1]) {
        cout << p << ", ";
    }
    cout << endl;

    cout << s.hasCommonAncestor(4, 7) << endl;
    cout << s.hasCommonAncestor(7, 8) << endl;
    cout << s.hasCommonAncestor(1, 4) << endl;

    pair<int, int> parent(-1, 0);
    s.findFurthestParent(8, parent, 0);
    cout<<parent.first<<endl;

    return 0;
}
