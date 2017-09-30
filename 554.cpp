#include<iostream>
#include<vector>
#include<unordered_map>
class Solution{
public:
	int leastBricks(vector<vector<int>>& wall){
		if(wall.size()==0)
			return 0;
		unordered_map<int,int> m;
		for(auto row:wall){
			int sum=0;
			for(int i=0;i+1<row.size();++i){
				sum+=row[i];
				m[sum]++;
			}
		}
		int height=wall.size();
		int maxEdge=0;
		for(auto it=m.begin();it!=m.end();++it){
			maxEdge=max(maxEdge,it->second);
		}
		return height-maxEdge;
	}
};

int main(){

}
