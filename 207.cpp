/*
There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to
first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it
possible for you to finish all courses?

Example 1:

Input: 2, [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0. So it is
possible. Example 2:

Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0, and to take
course 0 you should also have finished course 1. So it is impossible. Note:

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
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
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

        int cnt = 0;
        while (!q.empty()) {
            int prere = q.front();
            q.pop();
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

        return cnt == numCourses;
    }
};

int main() {
    Solution s;
    vector<pair<int, int>> pre = {{1, 0}};
    int numCourses = 2;
    cout << s.canFinish(numCourses, pre) << endl;

    return 0;
}
