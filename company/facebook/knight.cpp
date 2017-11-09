/*
 
 Given a square chessboard of N x N size, the position of Knight and position of a target is given. We need to find out minimum steps a Knight will take to reach the target position.
 
 supposed the size is unlimited now.(facebook interview.)
 
 */

#include<iostream>
#include<vector>
#include<queue>
#include<set>

using namespace std;

class Solution{
public:
	int dx[8]={-1,1,-2,2,-1,1,-2,2};
	int dy[8]={2,2,1,1,-2,-2,-1,-1};

	struct state{
		int x,y;
		int step;
		state(int m,int n,int s=0):x(m),y(n),step(s){}
	};

	int minSteps(vector<int>& start,vector<int>& end){
		if(start==end)	
			return 0;
		set<pair<int,int>> visit;
		state s(start[0],start[1],0);
		visit.insert({start[0],start[1]});
		queue<state> q;
		q.push(s);
		while(!q.empty()){
			state tmp=q.front();
			q.pop();
			for(int i=0;i<8;++i){
				if(visit.count({tmp.x+dx[i],tmp.y+dy[i]}))
					continue;
				state next(tmp.x+dx[i],tmp.y+dy[i],tmp.step+1);
				if(next.x==end[0]&&next.y==end[1])
					return next.step;
				q.push(next);
			}
		}
		return -1;
	}
};

int main(){
	vector<int> start={4,5};
	vector<int> end={1,1};
	//expected value: 3 steps

	Solution s;
	cout<<s.minSteps(start,end)<<endl;

	return 0;
}





