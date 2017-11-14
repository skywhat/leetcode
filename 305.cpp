#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> dir={{-1,0},{1,0},{0,1},{0,-1}};
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> root(m*n,-1);
        vector<int> res;
        int cnt=0;
        for(auto p:positions){
            cnt++;
            int cur=p.first*n+p.second;
            root[cur]=cur;
            for(auto d:dir){
                int x=p.first+d[0];
                int y=p.second+d[1];
                int nbor=x*n+y;
                if(x<0||x>=m||y<0||y>=n||root[nbor]==-1)//not valid
                    continue;
                int rootNbor=find(root,nbor);
                if(find(root,cur)!=rootNbor){
                    cnt--;
                    root[cur]=rootNbor;// union two disjoint set
                    cur=rootNbor;//update the cur to parent
                }
                
            }
            res.push_back(cnt);
        }
        return res;
    }
    int find(vector<int>& root,int id){
        while(root[id]!=id){
            root[id]=root[root[id]];//path compression lg(n)
            id=root[id];
        }
        return id;
    }
};

int main(){
    
    
}
