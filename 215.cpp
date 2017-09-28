#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

class Solution{
public:
	int findKthLargest(vector<int>& nums,int k){
		sort(nums.begin(),nums.end());
		return nums[nums.size()-k];
	}
};

class Solution2{
public:
	int findKthLargest(vector<int>& nums,int k){
		priority_queue<int> q(nums.begin(),nums.end());
		for(int i=1;i<k;++i)
			q.pop();
		return q.top();
	}
};

class Solution3{
public:
	int findKthLargest(vector<int>& nums,int k){
		int left=0,right=nums.size()-1;
		while(left<=right){
			int pt=partition(nums,left,right);
			if(pt==k-1)
				return nums[pt];
			else if(pt>k-1)
				right=pt-1;
			else
				left=pt+1;
		}
		return -1;
	}
	//left part: elements larger than the pivot
	//right part: elements smaller than the pivot
	//central part: the pivot
	//return the position of the pivot
	int partition(vector<int>& nums,int left,int right){
		int pivot=nums[left];
		int l=left+1,r=right;
		while(l<=r){
			if(nums[l]<pivot&&nums[r]>pivot)
				swap(nums[l++],nums[r--]);
			if(nums[l]>=pivot)
				l++;
			if(nums[r]<=pivot)
				r--;
		}
		swap(nums[left],nums[r]);
		return r;
	}
};


int main(){
	vector<int> test={3,2,1,5,6,4};
	int k=2;
	Solution3 s;
	cout<<s.findKthLargest(test,k)<<endl;

	return 0;

}
