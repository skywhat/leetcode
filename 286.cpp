#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.size()==0)
            return;
        int m=rooms.size();
        int n=rooms[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;++j){
                if(rooms[i][j]==0){
                    findDist(rooms,0,i,j,m,n);
                }
            }
        }
    }
    void findDist(vector<vector<int>>& rooms,int dist,int i,int j,const int& m,const int& n){
        if(rooms[i][j]==-1||rooms[i][j]<dist)
            return;
        rooms[i][j]=dist;
        if(i-1>=0)
            findDist(rooms,dist+1,i-1,j,m,n);
        if(i+1<m)
            findDist(rooms,dist+1,i+1,j,m,n);
        if(j-1>=0)
            findDist(rooms,dist+1,i,j-1,m,n);
        if(j+1<n)
            findDist(rooms,dist+1,i,j+1,m,n);
    }
};

class Solution2 {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if(rooms.size()==0)
            return;
        vector<vector<int>> dirs={{-1,0},{1,0},{0,1},{0,-1}};
        queue<pair<int,int>> q;
        for(int i=0;i<rooms.size();++i){
            for(int j=0;j<rooms[0].size();++j){
                if(rooms[i][j]==0)
                    q.push(make_pair(i,j));
            }
        }
        while(!q.empty()){
            pair<int,int> temp=q.front();
            q.pop();
            for(auto d:dirs){
                int x=temp.first+d[0];
                int y=temp.second+d[1];
                if(x>=0&&x<rooms.size()&&y>=0&&y<rooms[0].size()&&rooms[x][y]!=-1){
                    if(rooms[x][y]>rooms[temp.first][temp.second]+1){
                        rooms[x][y]=rooms[temp.first][temp.second]+1;
                        q.push(make_pair(x,y));
                    }
                }
            }
        }
    }
};

int main(){
}
