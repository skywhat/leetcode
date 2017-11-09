/*
 
 Given a square chessboard of N x N size, the position of Knight and position of a target is given. We need to find out minimum steps a Knight will take to reach the target position.
 
 supposed the size is unlimited now.(facebook interview.)
 
 */

#include<iostream>
#include<vector>
#include<queue>

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

	int minSteps(vector<int>& start,vector<int>& end,int width){
		vector<vector<int>> visit(width,vector<int>(width,0));
		if(start==end)	
			return 0;
		state s(start[0],start[1],0);
		visit[start[0]][start[1]]=1;
		queue<state> q;
		q.push(s);
		while(!q.empty()){
			state tmp=q.front();
			q.pop();
			for(int i=0;i<8;++i){
				if(visit[tmp.x+dx[i]][tmp.y+dy[i]])
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
	int width=1000;
	vector<int> start={14,15};
	vector<int> end={11,11};
	//expected value: 3 steps

	Solution s;
	cout<<s.minSteps(start,end,width)<<endl;

	return 0;
}





