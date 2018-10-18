// Equations are given in the format A / B = k, where A and B are variables
// represented as strings, and k is a real number (floating point number). Given
// some queries, return the answers. If the answer does not exist, return -1.0.
//
// Example:
// Given a / b = 2.0, b / c = 3.0.
// queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
// return [6.0, 0.5, -1.0, 1.0, -1.0 ].
//
// The input is: vector<pair<string, string>> equations, vector<double>& values,
// vector<pair<string, string>> queries , where equations.size() ==
// values.size(), and the values are positive. This represents the equations.
// Return vector<double>.
//
// According to the example above:
//
// equations = [ ["a", "b"], ["b", "c"] ],
// values = [2.0, 3.0],
// queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
// The input is always valid. You may assume that evaluating the queries will
// result in no division by zero and there is no contradiction.

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations,
                                vector<double>& values,
                                vector<pair<string, string>> queries) {
        map<string, map<string, double>> m;
        int n = equations.size();

        for (int i = 0; i < n; ++i) {
            m[equations[i].first][equations[i].second] = values[i];
            m[equations[i].second][equations[i].first] = 1 / values[i];
        }

        vector<double> res(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            res[i] = dfs(queries[i].first, queries[i].second, set<string>(),
                         1.0, m);
        }
        return res;
    }

    double dfs(string start,
               string end,
               set<string> seen,
               double val,
               map<string, map<string, double>>& m) {
        if (!m.count(start) || seen.count(start)) {
            return -1;
        }
        if (start == end) {
            return val;
        }

        seen.insert(start);
        map<string, double> next = m[start];
        for (auto item : next) {
            double res = dfs(item.first, end, seen, val * item.second, m);
            if (res != -1) {
                return res;
            }
        }

        return -1;
    }
};
