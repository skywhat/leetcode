#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution{
public:
	int findMaximumXOR(vector<int>& nums){
		int res=0,mask=0;
		unordered_set<int> s;
		for(int i=31;i>=0;--i){
			s.clear();
			mask=mask|(1<<i);
			for(auto num:nums){
				s.insert(num&mask);
			}
			int candidate=res|(1<<i);
			for(auto prefix:s){
				if(s.count(prefix^candidate)){
					res=candidate;
					break;
				}
			}
		}
		return res;
	}
};

int main(){
	vector<int> v={8,10,2};
	Solution s;
	cout<<s.findMaximumXOR(v)<<endl;

	return 0;
}

