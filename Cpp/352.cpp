// Given a data stream input of non-negative integers a1, a2, ..., an, ...,
// summarize the numbers seen so far as a list of disjoint intervals.
//
// For example, suppose the integers from the data stream are 1, 3, 7, 2, 6,
// ..., then the summary will be:
//
// [1, 1]
// [1, 1], [3, 3]
// [1, 1], [3, 3], [7, 7]
// [1, 3], [7, 7]
// [1, 3], [6, 7]
// Follow up:
// What if there are lots of merges and the number of disjoint intervals are
// small compared to the data stream's size?

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class SummaryRanges {
public:
    /** Initialize your data structure here. */
    struct comp {
        bool operator()(Interval i, Interval j) { return i.start < j.start; }
    };
    set<Interval, comp> s;

    SummaryRanges() {}

    void addNum(int val) {
        auto it = s.lower_bound(Interval(val, val));
        if (it != s.begin() && (--it)->end + 1 < val) {
            it++;
        }
        int start = val;
        int end = val;
        while (it != s.end() && it->start <= val + 1 && it->end >= val - 1) {
            start = min(it->start, start);
            end = max(it->end, end);
            it = s.erase(it);
        }
        s.insert(Interval(start, end));
    }

    vector<Interval> getIntervals() {
        vector<Interval> res;
        for (auto i : s) {
            res.push_back(i);
        }
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
