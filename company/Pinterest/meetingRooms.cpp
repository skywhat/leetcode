// 第一题：类似meeting rooms，输入是一个int[][] meetings, int start, int end,
// 每个数都是时间，13：00 =》 1300， 9：30 =》 930， 看新的meeting
// 能不能安排到meetings ex: {[1300, 1500], [930, 1200],[830, 845]},
// 新的meeting[820, 830], return true; [1450, 1500] return false;
//
// Int[] start = new int[meetings.length];
// Int[] end = new
//
// 第二题：类似merge
// interval，唯一的区别是输出，输出空闲的时间段，merge完后，再把两两个之间的空的输出就好，注意要加上0
// - 第一个的start time

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval(int s = 0, int e = 0) : start(s), end(e) {}
};

class Solution {
public:
    bool isValid(Interval cur, vector<Interval> meetings) {
        sort(meetings.begin(), meetings.end(),
             [](Interval l, Interval r) { return l.start < r.start; });

        for (auto i : meetings) {
            if (cur.start >= i.end || cur.end <= i.start) {
                continue;
            }
            return false;
        }

        return true;
    }

    vector<Interval> getFreeTime(vector<Interval> meetings) {
        if (meetings.empty()) {
            return {};
        }
        sort(meetings.begin(), meetings.end(),
             [](Interval l, Interval r) { return l.start < r.start; });

        vector<Interval> valid_meetings;
        valid_meetings.push_back(meetings[0]);
        for (int i = 1; i < meetings.size(); ++i) {
            if (valid_meetings.back().end < meetings[i].start) {
                valid_meetings.push_back(meetings[i]);
            } else {
                valid_meetings.back().end
                    = max(valid_meetings.back().end, meetings[i].end);
            }
        }

        vector<Interval> res;
        if (valid_meetings[0].start != 0) {
            res.push_back(Interval(0, valid_meetings[0].start));
        }
        for (int i = 1; i < valid_meetings.size(); ++i) {
            res.push_back({valid_meetings[i - 1].end, valid_meetings[i].start});
        }

        return res;
    }
};

int main() {
    Solution s;

    vector<int> start = {1300, 930, 830, 800};
    vector<int> end = {1500, 1200, 845, 840};
    vector<Interval> meetings;
    for (int i = 0; i < start.size(); ++i) {
        meetings.push_back(Interval(start[i], end[i]));
    }

    cout << s.isValid(Interval(700, 800), meetings) << endl;
    cout << s.isValid(Interval(1450, 1500), meetings) << endl;

    vector<Interval> free_time = s.getFreeTime(meetings);
    for (auto i : free_time) {
        cout << "start: " << i.start << " end: " << i.end << endl;
    }

    return 0;
}
