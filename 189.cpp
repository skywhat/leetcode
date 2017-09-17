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
