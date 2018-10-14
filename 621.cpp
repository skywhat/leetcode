// Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.
//
// However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.
//
// You need to return the least number of intervals the CPU will take to finish all the given tasks.
//
//
//
// Example:
//
// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
//
//
// Note:
//
// The number of tasks is in the range [1, 10000].
// The integer n is in the range [0, 100].

#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> t(26, 0);
        for (auto name : tasks) {
            t[name - 'A']++;
        }

        sort(t.begin(), t.end());
        int maxNum = t[25];
        int i = 25;
        for (; i >= 0 && t[i] == t[25]; --i)
            ;
        int predict = (t[25] - 1) * (n + 1) + 25 - i;
        int actual = tasks.size();
        return max(actual, predict);
    }
};

int main() {}
