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

class Solution4 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> q;
        for(int i=0;i<k;++i){
            q.push(nums[i]);
        }
        for(int i=k;i<nums.size();++i){
            if(q.top()<nums[i]){
                q.pop();
                q.push(nums[i]);
            }
        }
        return q.top();
    }
};

class Solution5 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len=nums.size();
        int i=0,j=len-1;
        while(i<=j){
            int pt=partition(nums,i,j);
            if(pt==len-k)
                return nums[pt];
            else if(pt>len-k)
                j=pt-1;
            else
                i=pt+1;
        }
        return -1;
    }
    //standard quick select
    int partition(vector<int>& nums,int i,int j){
        int val=nums[i];
        int l=i+1;
        int r=j;
        while(l<=r){
            if(nums[l]>val&&nums[r]<val)
                swap(nums[l++],nums[r--]);
            if(nums[l]<=val)
                l++;
            if(nums[r]>=val)
                r--;
        }
        swap(nums[i],nums[r]);
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
