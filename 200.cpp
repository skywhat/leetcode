class Solution{
public:
    int numIslands(vector<vector<char>>& grid){
        if(grid.empty())
            return 0;
        int cnt=0;
        const int m=grid.size();
        const int n=grid[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]=='1'){
                    cnt++;
                    flipToZero(grid,m,n,i,j);
                }
            }
        }
        return cnt;
    }
    
    void flipToZero(vector<vector<char>>& grid,const int& m,const int& n,int i,int j){
        if(grid[i][j]=='0')
            return;
        grid[i][j]='0';
        if(i+1<m)
            flipToZero(grid,m,n,i+1,j);
        if(i-1>=0)
            flipToZero(grid,m,n,i-1,j);
        if(j+1<n)
            flipToZero(grid,m,n,i,j+1);
        if(j-1>=0)
            flipToZero(grid,m,n,i,j-1);
    }
};

//union find
class Solution2 {
public:
    vector<vector<int>> dir={{-1,0},{1,0},{0,-1,},{0,1}};
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        if(!m)
            return 0;
        int cnt=0;
        int n=grid[0].size();
        vector<int> root(m*n,0);
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                root[i*n+j]=i*n+j;
                if(grid[i][j]=='1')
                    cnt++;
            }
        }
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]=='0')
                    continue;
                int cur=i*n+j;
                if(root[cur]!=cur)//this position has been unioned.
                    continue;
                for(auto&& d:dir){
                    int x=d[0]+i;
                    int y=d[1]+j;
                    if(x<0||x>=m||y<0||y>=n||grid[x][y]=='0')
                        continue;
                    int nb=x*n+y;
                    int rootNb=find(root,nb);
                    if(find(root,cur)!=rootNb){
                        root[cur]=rootNb;//union two disjoint sets
                        cur=rootNb;//update the cur to parent
                        cnt--;//two islands were unioned.
                    }
                }

            }
        }
        return cnt;
    }
    int find(vector<int>& root,int id){
        while(root[id]!=id){
            root[id]=root[root[id]];//path compression
            id=root[id];
        }
        return id;
    }
};

/*
 example:
 
 0 1 0
 1 0 1
 0 1 0
 
 For the central 0, it could be visited at most five times
 Thus the time complexity of DFS solution would be O(n)
 */


