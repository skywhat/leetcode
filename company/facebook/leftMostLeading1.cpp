#include<iostream>
#include<vector>

using namespace std;


//O(m+n)
class Solution{
public:
	int leftMost(vector<vector<int>>& grid){
		int m=grid.size();
		if(!m)
			return -1;
		int n=grid[0].size();
		int left=n-1;
		for(int i=0;i<m;++i){
			while(left-1>=0&&grid[i][left-1]==1)
				left--;
		}
		return left;
	}
};

//O(m*lgn)
class Solution2{
public:
	int leftMost(vector<vector<int>>& grid){
		int m=grid.size();
		if(!m)
			return -1;
		int n=grid[0].size();
		int left=INT_MAX;
		for(int i=0;i<m;++i){
			left=min(left,binarySearch(grid[i]));
		}
		return left;
	}
	//find the left most 1 in the array
	int binarySearch(vector<int>& nums){
		int i=0,j=nums.size()-1;
		while(i+1<j){
			int mid=i+(j-i)/2;
			if(nums[mid]==0)
				i=mid+1;
			else
				j=mid;
		}
		if(nums[i]==1)
			return i;
		else if(nums[j]==1)
			return j;
		else
			return INT_MAX;
	}
};


int main(){
	vector<vector<int>> grid={
		{0,0,0,1,1,1},
		{0,0,1,1,1,1},
		{0,0,0,0,0,1},
		{1,1,1,1,1,1}
	};

	vector<vector<int>> grid1={
		{0,0,0,0,0,1},
		{0,0,0,0,1,1},
		{0,0,1,1,1,1},
		{0,0,0,0,1,1}
	};

	Solution2 s;
	cout<<s.leftMost(grid)<<endl;
	//expected 0
	cout<<s.leftMost(grid1)<<endl;
	//expected 2
	return 0;
}
