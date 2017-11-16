/*

Give a matrix, for example
1 0 0 1 0
0 0 1 0 1
0 0 0 1 0
1 0 1 0 1
Find if there is a rectangle in the matrix, all four corners are 1
For the example,  there is only one rectangle, that is
1 0 1
0 1 0
1 0 1


 */

#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution{
public:
	bool hasRectangle(vector<vector<int>>& grid){
		int m=grid.size();
		if(m<2)
			return false;
		int n=grid[0].size();
		for(int i=0;i<m;++i){
			for(int j=0;j<n;++j){
				if(grid[i][j]==1){
					for(int x=i+1;x<m;++x){
						if(grid[x][j]==1){
							for(int y=j+1;y<n;++y){
								if(grid[i][y]==1&&grid[x][y]==1)
									return true;
							}
						}
					}
				}
			}
		}
		return false;
	};
};

class Solution2{
public:
	bool hasRectangle(vector<vector<int>>& grid){
		int m=grid.size();
		if(m<2)
			return false;
		int n=grid[0].size();
		vector<vector<int>> pos;
		for(int i=0;i<m;++i){
			vector<int> row;
			for(int j=0;j<n;++j){
				if(grid[i][j]==1)
					row.push_back(j);
			}
			pos.push_back(row);
		}
		for(int i=0;i<pos.size()-1;++i){
			for(int j=i+1;j<pos.size();++j){
				if(commonElement(pos[i],pos[j])>=2)
					return true;
			}
		}
		return false;

	}
	//obviously, v1 and v2 are sorted,and no duplicates
	int commonElement(const vector<int>& v1,const vector<int>& v2){
		int i=0,j=0;
		int cnt=0;
		while(i<v1.size()&&j<v2.size()){
			if(v1[i]<v2[j])
				i++;
			else if(v1[i]>v2[j])
				j++;
			else{
				i++;
				j++;
				cnt++;
			}
		}
		return cnt;
	}
};

int main(){
	Solution2 s;

	vector<vector<int>> grid={
		{1,0,0,1,0},
		{0,0,1,0,1},
		{0,0,0,1,0},
		{1,0,1,0,1}
	};

	vector<vector<int>> grid2={
		{1,0,0,1,0},
		{0,0,0,0,1},
		{0,0,0,1,0},
		{1,0,1,0,1}
	};
	
	cout<<s.hasRectangle(grid)<<endl;
	cout<<s.hasRectangle(grid2)<<endl;

	return 0;
}




