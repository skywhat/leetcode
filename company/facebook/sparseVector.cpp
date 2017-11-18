/*
 * given two sparse vectors, compute the dot product. 
 * Suppose we have very large sparse vectors, which contains a lot of zeros and double
 *
 * 1. find a data structure to store them
 * 2. get the dot product of them
 *
 */

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
public:
	int dotProduct(vector<pair<int,int>>& v1,vector<pair<int,int>>& v2){
		int res=0;
		unordered_map<int,int> m;//key: position  value: val
		for(auto&& v:v1){
			m[v.first]=v.second;
		}
		for(auto&& v:v2){
			if(m.find(v.first)!=m.end()){
				res+=v.second*m[v.first];
			}
		}
		return res;
	}
};

int main(){
	Solution s;
	vector<pair<int,int>> v1={
		{1,4},
		{4,2},
		{5,3}
	};
	vector<pair<int,int>> v2={
		{1,7},
		{2,6},
		{5,1}
	};

	int res=s.dotProduct(v1,v2);
	
	cout<<"after dot product: "<<res<<endl;

	return 0;
}


