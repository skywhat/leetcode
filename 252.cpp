/*
 Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
 
 For example,
 Given [[0, 30],[5, 10],[15, 20]],
 return false.
 

 */


#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Interval{
int start;
int end;
Interval():start(0),end(0){}
Interval(int s,int e):start(s),end(e){}
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval i, Interval j){
            return i.start < j.start;
        });
        
        int i=1;
        while(i<intervals.size()){
            if(intervals[i].start < intervals[i-1].end){
                return false;
            }
            i++;
        }
            
        return true;
    }
};
};

int main(){
	vector<Interval> test;
	test.push_back(Interval(0,30));
	test.push_back(Interval(5,10));
	test.push_back(Interval(15,20));
	
	Solution s;
	cout<<s.canAttendMeetings(test)<<endl;

	return 0;
}


