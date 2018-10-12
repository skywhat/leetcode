// We are given a list schedule of employees, which represents the working time
// for each employee.
//
// Each employee has a list of non-overlapping Intervals, and these intervals
// are in sorted order.
//
// Return the list of finite intervals representing common, positive-length free
// time for all employees, also in sorted order.
//
// Example 1:
// Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
// Output: [[3,4]]
// Explanation:
// There are a total of three employees, and all common
// free time intervals would be [-inf, 1], [3, 4], [10, inf].
// We discard any intervals that contain inf as they aren't finite.
// Example 2:
// Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
// Output: [[5,6],[7,9]]
// (Even though we are representing Intervals in the form [x, y], the objects
// inside are Intervals, not lists or arrays. For example, schedule[0][0].start
// = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined.)
//
// Also, we wouldn't include intervals like [5, 5] in our answer, as they have
// zero length.
//
// Note:
//
// schedule and schedule[i] are lists with lengths in range [1, 50].
// 0 <= schedule[i].start < schedule[i].end <= 10^8.

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        map<int, int> m;
        for (auto timelist : schedule) {
            for (auto time : timelist) {
                m[time.start]++;
                m[time.end]--;
            }
        }

        vector<Interval> res;
        int start = 0;

        for (auto t : m) {
            start += t.second;
            if (start == 0) {
                res.push_back(Interval(t.first, 0));
            }
            if (start != 0 && !res.empty() && !res.back().end) {
                res.back().end = t.first;
            }
        }

        if (!res.empty()) {
            res.pop_back();
        }

        return res;
    }
};

class Solution2 {
public:
    typedef pair<int, bool> pib;
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<pib> t;
        for (auto timelist : schedule) {
            for (auto time : timelist) {
                t.push_back({time.start, true});
                t.push_back({time.end, false});
            }
        }

        sort(t.begin(), t.end());

        int start = 0;
        int prev = t[0].first;
        vector<Interval> res;
        
        for (auto i : t) {
            if (i.second) {
                if (start == 0 && prev < i.first) {
                    res.push_back(Interval(prev, i.first));
                }
                start++;
            } else {
                if (start == 1) {
                    prev = max(prev, i.first);
                }
                start--;
            }
        }

        return res;
    }
};
