class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()){
            return 0;
        }
        
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;
        
        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                int area = 0;
                flipToZero(grid, i, j, m, n, area);
                maxArea = max(maxArea, area);
            }
        }
        
        return maxArea;
    }
    
    void flipToZero(vector<vector<int>>& grid, int i, int j, int m, int n, int& area){
        if(grid[i][j]){
            grid[i][j] = 0;
            area++;
            if(i-1>=0){
                flipToZero(grid, i-1, j, m, n, area);
            }
            if(i+1<m){
                flipToZero(grid, i+1, j, m, n, area);
            }
            if(j-1>=0){
                flipToZero(grid, i, j-1, m, n, area);
            }
            if(j+1<n){
                flipToZero(grid, i, j+1, m, n, area);
            }
        }
    }
};
