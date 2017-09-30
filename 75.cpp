#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	void sortColors(vector<int>& nums){
		vector<int> count(3,0);
		for(auto n:nums)
			count[n]++;
		for(int i=0,j=0;i<count.size();++i){
			while(count[i]){
				nums[j++]=i;
				count[i]--;
			}
		}
	}
};

int main(){
	vector<int> color={1,0,1,2,0,0,2,2};
	Solution s;
	s.sortColors(color);

	for(auto c:color)
		cout<<c<<", ";
	cout<<endl;

	return 0;

}
