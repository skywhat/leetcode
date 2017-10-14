#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> uf(n,-1);
        for(int i=0;i<edges.size();++i){
            int x=find(uf,edges[i].first);
            int y=find(uf,edges[i].second);
            if(x==y)
                return false;
            uf[x]=y;
        }
        return edges.size()==n-1?true:false;
        
    }
    int find(const vector<int>& uf,int node){
        if(uf[node]==-1)
            return node;
        else
            return find(uf,uf[node]);
    }
};

int main(){
}
