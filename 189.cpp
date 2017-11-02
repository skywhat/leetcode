#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
	void rotate(vector<int>& nums,int k){
		k=k%nums.size();
		int i=0,j=nums.size()-1;
		while(i<j){
			swap(nums[i++],nums[j--]);
		}
		i=0,j=k-1;
		while(i<j){
			swap(nums[i++],nums[j--]);
		}
		i=k,j=nums.size()-1;
		while(i<j){
			swap(nums[i++],nums[j--]);
		}
	}		
};

/*
 * How to change [0,1,2,3,4,5,6] to [4,5,6,0,1,2,3] by k = 3?
 *
 * We can change by the following rule:
 *
 *     [0]->[3], [3]->[6], [6]->[2],  [2]->[5], [5]->[1], [1]->[4]
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        int origin=0;
        int cur=0;
        int next=k;
        // we need two temporary variables to record numbers.
        int tmp1=nums[cur];
        int tmp2=nums[next];
        for(int i=0;i<nums.size();++i){
            nums[next]=tmp1;//tmp1 is the previous number
            tmp1=tmp2;
            cur=next;
            
            //if we meet a circle, move to the next one.
            if(cur==origin){
                origin=++cur;
                tmp1=nums[cur];
            }
            next=(cur+k)%n;
            tmp2=nums[next];
        }
    }
};

int main(){
	vector<int> test={1,2,3,4,5,6,7};
	int k=3;
	Solution s;
	s.rotate(test,k);
	for(auto t:test)
		cout<<t<<" ,";
	cout<<endl;

	return 0;
}
