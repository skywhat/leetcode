#include<iostream>
#include<queue>
#include<vector>
#include<list>

using namespace std;

typedef pair<int,int> pii;
struct compare{
	bool operator()(const pii& a,const pii& b){
		return a.second>b.second;
	}
};
vector<int> dijkstra(vector<list<pii>> graph,int src){
	priority_queue<pii,vector<pii>,compare> q;
	vector<int> distances(graph.size(),INT_MAX);
	vector<bool> visited(graph.size(),false);
	distances[src]=0;
	q.push({src,0});
	while(!q.empty()){
		pii cur=q.top();
		q.pop();
		cout<<"currently at "<<cur.first<<endl;
		if(!visited[cur.first]){
			visited[cur.first]=true;
			for(auto vertex=graph[cur.first].begin();vertex!=graph[cur.first].end();++vertex){
				if(cur.second+vertex->second<distances[vertex->first]){
					distances[vertex->first]=cur.second+vertex->second;
					q.push(make_pair(vertex->first,distances[vertex->first]));
				}
			}
		}
	}
	return distances;
}


int main(){
	vector<list<pii>> graph;
	int v,e,src,des,weight;
	cin>>v>>e;
	graph.resize(v);
	while(e--){
		cin>>src>>des>>weight;
		graph[src].push_back(make_pair(des,weight));		
	}
	cin>>src;
	vector<int> distances=dijkstra(graph,src);
	for(auto itr=distances.begin();itr!=distances.end();++itr){
		cout<<*itr<<" ";
	}

	return 0;
}











