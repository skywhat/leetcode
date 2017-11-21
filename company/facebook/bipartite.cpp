/*
 * check whether a given graph is bipartite or not
 *
 *
 */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution{
public:
	bool isBipartite(vector<vector<int>>& graph){
		int n=graph.size();
		vector<int> color(n,-1);
		int src=0;
		color[0]=1;
		queue<int> q;
		q.push(src);
		while(!q.empty()){
			int cur=q.front();
			q.pop();
			//a self loop
			if(graph[cur][cur]==1)
				return false;
			for(int i=0;i<n;++i){
				if(graph[cur][i]&&color[i]==-1){
					//assign alternate color to this adjacent edge i to cur
					color[i]=1-color[cur];
					q.push(i);
				}
				//an edge from cur to i exists and has the same color, not a bipartite
				else if(graph[cur][i]&&color[i]==color[cur])
					return false;
			}
		}
		return true;
	}
};

int main(){
	vector<vector<int>> graph={
		{0,1,0,1},
		{1,0,1,0},
		{0,1,0,1},
		{1,0,1,0}
	};

	Solution s;
	cout<<s.isBipartite(graph)<<endl;

	return 0;

}
