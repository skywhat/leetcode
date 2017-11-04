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

/*
 example:
 
 0 1 0
 1 0 1
 0 1 0
 
 For the central 0, it could be visited at most five times
 Thus the time complexity of DFS solution would be O(n)
 */


