/*
 *
 * given 2 list of interval representing users online offline timestamp e.g (already sorted), find all intervals that both of users are online.e.g A= [(3, 5), (7, 11)] B=[(2, 4), (9, 10)] --> [(3, 4), (9, 10)].
 *
 */

#include<iostream>
#include<vector>

using namespace std;

struct Interval{
	int start;
	int end;
	Interval():start(0),end(0){}
	Interval(int s,int e):start(s),end(e){}
};

class Solution{
public:
	vector<Interval> overlap(vector<Interval>& a,vector<Interval>& b){
		vector<Interval> res;
		int i=0,j=0;
		while(i<a.size()&&j<b.size()){
			if(a[i].end<=b[j].start){
				i++;
			}
			else if(a[i].start>=b[j].end){
				j++;
			}
			else{
				Interval tmp(max(a[i].start,b[j].start),min(a[i].end,b[j].end));
				res.push_back(tmp);
				if(a[i].end>=b[j].end)
					j++;
				else
					i++;
			}

		}
		return res;
	}
};

int main(){
	Solution s;
	vector<Interval> a={{3,5},{7,11}};	
	vector<Interval> b={{2,4},{9,11}};
	
	auto res=s.overlap(a,b);
	for(auto item:res){
		cout<<item.start<<", "<<item.end<<endl;
	}

	return 0;
}




