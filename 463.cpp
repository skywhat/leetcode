#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.empty()){
            return 0;
        }
        
        int brick = 0, seam = 0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]){
                    brick++;
                    if(i-1>=0 && grid[i-1][j]){
                        seam++;
                    }
                    if(i+1<grid.size() && grid[i+1][j]){
                        seam++;
                    }
                    if(j-1>=0 && grid[i][j-1]){
                        seam++;
                    }
                    if(j+1<grid[0].size() && grid[i][j+1]){
                        seam++;
                    }
                }
            }
        }
        
        return 4*brick - seam;
    }
};

int main(){
	vector<vector<int>> grid = {
		{0,1,0,0},
		{1,1,1,0},
		{0,1,0,0},
		{1,1,0,0},
	};

	int expect = 16;
	Solution s;
	cout<<(s.islandPerimeter(grid) == expect) <<endl;

	return 0;
}
