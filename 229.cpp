#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
public:
	vector<int> majorityElement(vector<int>& nums){
		unordered_map<int> m;
		int limit=m.size()/3;
		vector<int> res;
		for(auto n:nums){
			if(m[n]++==limit)
				res.push_back(n);
		}
		return res;
	}
};

int main(){

}
