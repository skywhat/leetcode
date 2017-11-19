/*
 * given a two dimensional array, a start point, and a end point.
 * 1 denotes the way you cannot go, 0 denotes the way you can go.
 * print the shortest path from start point to end point.
 *
 */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct point{
	int x;
	int y;
	int dist;
	point(int _x=0,int _y=0,int _dist=0):x(_x),y(_y),dist(_dist){}

};

class Solution{
private:
	vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
public:
	vector<point> shortest(vector<vector<int>>& grid,point& start,point& end){
		vector<point> path;
		if(grid.empty())
			return path;
		if(start.x==end.x&&start.y==end.y)
			return path;
		queue<point> q;
		int m=grid.size();
		int n=grid[0].size();
		vector<vector<point>> visit(m,vector<point>(n,{-1,-1,-1}));
		q.push(start);
		while(!q.empty()){
			auto tmp=q.front();
			q.pop();
			for(auto&& d:dir){
				point next(tmp.x+d[0],tmp.y+d[1],tmp.dist+1);
				if(isValid(next,grid,m,n)&&visit[next.x][next.y].dist==-1){
					visit[next.x][next.y]=tmp;
					if(next.x==end.x&&next.y==end.y){
						findPath(visit,path,start,end);
						return path;
					}
					else
						q.push(next);
				}
			}
		}
		return path;
	}
	bool isValid(point& next,const vector<vector<int>>& grid,const int& m,const int& n){
		if(next.x<0||next.x>=m||next.y<0||next.y>=n||grid[next.x][next.y]==1)
			return false;
		return true;
	}
	void findPath(const vector<vector<point>>& visit,vector<point>& path,point start,point end){
		path.push_back(end);
		while(end.x!=start.x||end.y!=start.y){
			end=visit[end.x][end.y];
			path.push_back(end);
		}
		reverse(path.begin(),path.end());
	}
};

int main(){
	vector<vector<int>> grid={
		{1,0,0,1,0,0,1},
		{0,1,0,0,0,1,0},
		{0,0,0,1,0,0,0},
		{1,0,0,0,1,0,0}
	};
	point start(3,2,0);
	point end(3,6,0);

	Solution s;
	auto path=s.shortest(grid,start,end);

	for(auto&& p:path){
		cout<<"("<<p.x<<", "<<p.y<<") -> ";
	}
	cout<<"end"<<endl;
//(3, 2) -> (2, 2) -> (1, 2) -> (1, 3) -> (1, 4) -> (2, 4) -> (2, 5) -> (3, 5) -> (3, 6) -> end	
	return 0;

}
