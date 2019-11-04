// Given an array of meeting time intervals consisting of start and end times
// [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms
// required.
//
// Example 1:
//
// Input: [[0, 30],[5, 10],[15, 20]]
// Output: 2
// Example 2:
//
// Input: [[7,10],[2,4]]
// Output: 1

#include <iostream>
#include <vector>

using namespace std;

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
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> start(n, 0);
        vector<int> end(n, 0);
        for (int i = 0; i < intervals.size(); ++i) {
            start[i] = intervals[i].start;
            end[i] = intervals[i].end;
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int room = 0;
        int endindex = 0;

        for (int i = 0; i < start.size(); ++i) {
            if (start[i] < end[endindex]) {
                room++;
            } else {
                endindex++;
            }
        }

        return room;
    }
};

class Solution2 {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        map<int, int> m;

        for (int i = 0; i < intervals.size(); ++i) {
            m[intervals[i].start]++;
            m[intervals[i].end]--;
        }

        int maxRoom = 0;
        int sum = 0;

        for (auto it : m) {
            sum += it.second;
            maxRoom = max(maxRoom, sum);
        }

        return maxRoom;
    }
};
