#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution{
public:
	struct node{
		int val;
		int row;//which row 
		int col;//which column
		node(int v=0,int r=0,int c=0):val(v),row(r),col(c){}
	};

	//we will construct a min heap.
	struct compare{
		bool operator()(const node& n1,const node& n2){
			return n1.val>n2.val;//priority queue is constructed by vector, the top one is the back
		}
	};

	double median(vector<vector<int>>& nums){
		priority_queue<node,vector<node>,compare> q;
		int sum=0;
		for(int i=0;i<nums.size();++i){
			if(nums[i].size()){
				q.push({nums[i][0],i,0});
				sum+=nums[i].size();
			}
		}
		int mid=sum/2;
		int cnt=1;
		double prev=0;
		while(cnt<=mid){
			//pop out mid numbers. 
			//if we have 9 numbers,we need pop out 4 numbers, the one in the top would be the median
			next(q,nums,prev);
			cnt++;
		}
		if(sum&1){//odd sum
			return q.top().val;
		}
		else{//even sum
			return (prev+q.top().val)/2;
		}
	}
	void next(priority_queue<node,vector<node>,compare>& q,vector<vector<int>>& nums,double& prev){
		auto tmp=q.top();
		prev=tmp.val;//record the previous value
		q.pop();
		if(tmp.col+1<nums[tmp.row].size()){//if this row still has number, push it into the heap.
			tmp.col++;
			tmp.val=nums[tmp.row][tmp.col];
			q.push(tmp);
		}
	}

};

int main(){
	vector<vector<int>> nums={
		{3,7,9},
		{4,8,15},
		{2,3,9}
	};//expected 7

	vector<vector<int>> nums2={
		{1,4,6,7,8},
		{},
		{3,5,9,11,13},
		{0,2,10,15,16,20}
	};//expected (7+8)/2=7.5

	Solution s;
	cout<<s.median(nums2)<<endl;

	return 0;

}
