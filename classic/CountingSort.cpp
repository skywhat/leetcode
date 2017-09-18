#include<iostream>
#include<vector>

using namespace std;

vector<int> sort(const vector<int>& nums,int range){
	vector<int> sorted(nums.size());
	vector<int> count(range+1);
	for(auto n:nums)
		count[n]++;
	for(int i=1;i<count.size();++i){
		count[i]+=count[i-1];
	}
	for(int i=nums.size()-1;i>=0;--i){
		sorted[count[nums[i]]-1]=nums[i];
		count[nums[i]]--;
	}
	return sorted;
}

int main(){
	vector<int> nums={1,4,1,2,7,5,2};
	int maxValue=0;
	for(auto n:nums)
		maxValue=max(n,maxValue);
	vector<int> sortedNums=sort(nums,maxValue);

	for(auto s:sortedNums)
		cout<<s<<", ";
	cout<<endl;

	return 0;

}
