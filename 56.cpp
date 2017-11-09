/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

#include<iostream>
#include<vector>
#include<string>
#include<iterator>
#include<algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() :start(0), end(0) {}
	Interval(int s, int e) :start(s), end(e) {}
	friend ostream& operator<<(ostream& os, const Interval& i) {
		os << "start: " << i.start << " end: " << i.end;
		return os;
	}
};
class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> res;
		sort(intervals.begin(), intervals.end(), [](Interval i,Interval j) {
			return i.start < j.start;
		});
		int size = intervals.size();
		for (int i = 0; i < size;i++) {
			Interval tmp = intervals[i];
			while (i+1<size&&tmp.end >= intervals[i + 1].start) {
				if (tmp.end < intervals[i+1].end)
					tmp.end = intervals[i+1].end;
				i++;
			}
			res.push_back(tmp);
		}
		return res;
	}
};

class Solution2 {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size()<2){
            return intervals;
        }
        vector<Interval> res;
        sort(intervals.begin(),intervals.end(),[](Interval i,Interval j){
            return i.start<j.start;
        });
        res.push_back(intervals[0]);
        for(int i=1;i<intervals.size();++i){
            if(res.back().end<intervals[i].start)
                res.push_back(intervals[i]);
            else
                res.back().end=max(res.back().end,intervals[i].end);
        }
        return res;
    }
};


int main() {
	Solution s;
	vector<vector<int>> given = { {1,3},{2,6},{8,10},{15,18} };
	vector<Interval> v;
	for (int i = 0; i < given.size(); ++i) {
		v.push_back(Interval(given[i][0],given[i][1]));
	}
	cout << "before:" << endl;
	copy(v.begin(),v.end(),ostream_iterator<Interval>(cout,"\n"));
	vector<Interval> res;
	res=s.merge(v);
	cout << "after:" << endl;
	copy(res.begin(),res.end(),ostream_iterator<Interval>(cout,"\n"));
	/*
	for (auto i : res)
		cout << "start: " << i.start << " end: " << i.end << endl;
	*/
	return 0;
}

