/*
 *
 * |X|X|O|O|O| *
 * |O|X|O|O|O| *
 * |O|O|O|O|O| *
 * |O|O|O|O|O| * 
 *	find the shortest steps from the leftmost column to the rightmost column.
 *
 */

#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

class Solution{
private:
	vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
public:
	struct point{
		int x;
		int y;
		int dist;
		point(int _x=0,int _y=0,int _dist=0):x(_x),y(_y),dist(_dist){}
	};
	int shortest(vector<vector<char>>& grid){
		int step=INT_MAX;
		for(int i=0;i<grid.size();++i){
			if(grid[i][0]=='O'){
				point start(i,0,0);
				step=min(step,shortest(grid,start));
			}
		}
		return step;
	}
	int shortest(const vector<vector<char>>& grid,point start){
		int m=grid.size();
		int n=grid[0].size();
		vector<vector<bool>> visited(m,vector<bool>(n,false));
		queue<point> q;
		q.push(start);
		visited[start.x][start.y]=true;
		while(!q.empty()){
			point tmp=q.front();
			q.pop();
			for(auto&& d:dir){
				point next(tmp.x+d[0],tmp.y+d[1],tmp.dist+1);
				if(isValid(grid,m,n,next)&&visited[next.x][next.y]==false){
					if(grid[next.x][next.y]=='*')
						return next.dist;
					else{
						q.push(next);
						visited[next.x][next.y]=true;
					}
				}
			}
		}
		return INT_MAX;
	}	
	bool isValid(const vector<vector<char>>& grid,const int& m,const int& n,point next){
		if(next.x<0||next.x>=m||next.y<0||next.y>=n||grid[next.x][next.y]=='X')
			return false;
		return true;
	}

};

int main(){
	vector<string> test={
	"XOOOX*",
	"OXXXO*",
	"OXOOO*",
	"XXOXO*",
	"OOOXX*",
	"OXXOO*"
	};
	vector<vector<char>> grid;
	for(int i=0;i<test.size();++i){
		vector<char> tmp;
		for(auto c:test[i])
			tmp.push_back(c);
		grid.push_back(tmp);
	}

	Solution s;
	cout<<s.shortest(grid)<<endl;

	return 0;

}

