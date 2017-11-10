class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea=0;
        int m=grid.size();
        if(!m)
            return 0;
        int n=grid[0].size();
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                if(grid[i][j]==1){
                    int area=0;
                    flipToZero(grid,i,j,m,n,area);
                    maxArea=max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
    void flipToZero(vector<vector<int>>& grid,int i,int j,const int& m,const int& n,int& area){
        if(grid[i][j]==1){
            grid[i][j]=0;
            area++;
            if(i+1<m)
                flipToZero(grid,i+1,j,m,n,area);
            if(i-1>=0)
                flipToZero(grid,i-1,j,m,n,area);
            if(j+1<n)
                flipToZero(grid,i,j+1,m,n,area);
            if(j-1>=0)
                flipToZero(grid,i,j-1,m,n,area);
        }
        
    }
};
