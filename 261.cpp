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

class Solution2 {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> uf(n,0);
        for(int i=0;i<n;++i)
            uf[i]=i;
        for(auto&& e:edges){
            int l=find(uf,e.first);
            int r=find(uf,e.second);
            if(l!=r){
                uf[l]=r;
            }
            else
                return false;
        }
        return edges.size()==n-1;
        
    }
    int find(vector<int>& uf,int id){
        while(uf[id]!=id){
            uf[id]=uf[uf[id]];//path compression.
            id=uf[id];
        }
        return id;
    }
};

int main(){
}
