#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Interval{
	int start;
	int end;
	Interval():start(0),end(0){}
	Interval(int s,int e):start(s),end(e){}
};

class Solution{
public:
    int eraseOverlapIntervals(vector<Interval>& intervals){
        if(intervals.size()<=1)
            return 0;
        sort(intervals.begin(),intervals.end(),[](Interval i,Interval j){
            return i.end<j.end;
        });
        int cnt=0;
        Interval temp=intervals[0];
        for(int i=1;i<intervals.size();++i){
            if(intervals[i].start<temp.end)
                cnt++;
            else
                temp=intervals[i];
        }
        return cnt;
    }
};

int main(){
	vector<Interval> intervals={{1,2},{2,3},{3,4},{1,3}};
	vector<Interval> intervals2={{1,2},{1,2},{1,2}};
	vector<Interval> intervals3={{1,2},{2,3}};
	Solution s;
	cout<<s.eraseOverlapIntervals(intervals3)<<endl;

	return 0;
}
