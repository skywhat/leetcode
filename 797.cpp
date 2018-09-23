// Given a directed, acyclic graph of N nodes.  Find all possible paths from
// node 0 to node N-1, and return them in any order.
//
// The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.
// graph[i] is a list of all nodes j for which the edge (i, j) exists.
//
// Example:
// Input: [[1,2], [3], [3], []]
// Output: [[0,1,3],[0,2,3]]
// Explanation: The graph looks like this:
// 0--->1
// |    |
// v    v
// 2--->3
// There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
// Note:
//
// The number of nodes in the graph will be in the range [2, 15].
// You can print different paths in any order, but you should keep the order of
// nodes inside one path.

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> res;
        vector<int> path = {0};
        traverse(res, path, 0, graph);
        return res;
    }

    void traverse(vector<vector<int>>& res,
                  vector<int> path,
                  int start,
                  const vector<vector<int>>& graph) {
        if (start + 1 == graph.size()) {
            res.push_back(path);
            return;
        }

        if (graph[start].empty()) {
            return;
        }

        for (auto node : graph[start]) {
            path.push_back(node);
            traverse(res, path, node, graph);
            path.pop_back();
        }
    }
};
