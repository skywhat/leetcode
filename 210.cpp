/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to
first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, return the
ordering of courses you should take to finish all courses.

There may be multiple correct orders, you just need to return one of them. If it
is impossible to finish all courses, return an empty array.

Example 1:

Input: 2, [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should
have finished course 0. So the correct course order is [0,1] . Example 2:

Input: 4, [[1,0],[2,0],[3,1],[3,2]]
Output: [0,1,2,3] or [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should
have finished both courses 1 and 2. Both courses 1 and 2 should be taken after
you finished course 0. So one correct course order is [0,1,2,3]. Another correct
ordering is [0,2,1,3] . Note:

The input prerequisites is a graph represented by a list of edges, not adjacency
matrices. Read more about how a graph is represented. You may assume that there
are no duplicate edges in the input prerequisites.
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses,
                          vector<pair<int, int>>& prerequisites) {
        vector<int> degree(numCourses, 0);
        for (auto&& p : prerequisites) {
            degree[p.first]++;
        }

        queue<int> q;
        for (int i = 0; i < degree.size(); ++i) {
            if (degree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> toposort;
        int cnt = 0;
        while (!q.empty()) {
            int prere = q.front();
            q.pop();
            toposort.push_back(prere);
            cnt++;

            for (auto& p : prerequisites) {
                if (p.second == prere) {
                    p.second = -1;
                    if (--degree[p.first] == 0) {
                        q.push(p.first);
                    }
                }
            }
        }

        return cnt == numCourses ? toposort : vector<int>();
    }
};

int main() {
    vector<pair<int, int>> pre = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    int numCourses = 4;
    Solution s;
    vector<int> res = s.findOrder(numCourses, pre);
    for (auto c : res) {
        cout << c << " -> ";
    }
    cout << endl;
    return 0;
}
