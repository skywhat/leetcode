// DescriptionHintsSubmissionsDiscussSolution
// An undirected, connected tree with N nodes labelled 0...N-1 and N-1 edges are
// given.
//
// The ith edge connects nodes edges[i][0] and edges[i][1] together.
//
// Return a list ans, where ans[i] is the sum of the distances between node i
// and all other nodes.
//
// Example 1:
//
// Input: N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
// Output: [8,12,6,10,10,10]
// Explanation:
// Here is a diagram of the given tree:
//   0
//  / \
// 1   2
//    /|\
//   3 4 5
// We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
// equals 1 + 1 + 2 + 2 + 2 = 8.  Hence, answer[0] = 8, and so on.
// Note: 1 <= N <= 10000

class Solution {
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<set<int>> tree(N);
        for (auto e : edges) {
            tree[e[0]].insert(e[1]);
            tree[e[1]].insert(e[0]);
        }
        vector<int> count(N); // count subtree node sizes
        vector<int> res(N);   // sum of subtree distances to node
        set<int> seen;
        dfs(0, count, res, tree, seen);
        seen.clear();
        compute(0, count, res, tree, seen, N);
        return res;
    }

    void dfs(int root,
             vector<int>& count,
             vector<int>& res,
             vector<set<int>>& tree,
             set<int>& seen) {
        seen.insert(root);
        for (auto i : tree[root]) {
            if (!seen.count(i)) {
                dfs(i, count, res, tree, seen);
                count[root] += count[i];
                res[root] += res[i] + count[i];
            }
        }
        count[root] += 1;
    }

    void compute(int root,
                 vector<int>& count,
                 vector<int>& res,
                 vector<set<int>>& tree,
                 set<int>& seen,
                 int& N) {
        seen.insert(root);
        for (auto i : tree[root]) {
            if (!seen.count(i)) {
                res[i] = res[root] - count[i] + N - count[i];
                compute(i, count, res, tree, seen, N);
            }
        }
    }
};
