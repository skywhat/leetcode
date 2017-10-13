/*
 * Given an array of n prime numbers, return all the products in the prime numbers.
 * input: 2,3,5
 * ouput: 6,10,15,30
 */
#include<iostream>
#include<unordered_set>
#include<iterator>

#include<vector>

using namespace std;

class Solution{
public:
	vector<int> productNum(vector<int>& prime){
		vector<int> res;
		product(prime,res,0,0,1);
		return res;
	}
	void product(const vector<int>& prime,vector<int>& res,int cnt,int pos,int temp){
		if(pos==prime.size()){
			if(cnt>1)
				res.push_back(temp);
			return;
		}
		product(prime,res,cnt,pos+1,temp);
		temp*=prime[pos];
		product(prime,res,cnt+1,pos+1,temp);
	}
};

int main(){
	vector<int> prime={2,3,5,7,11,13};
	Solution s;
	vector<int> res=s.productNum(prime);
	copy(res.begin(),res.end(),ostream_iterator<int>(cout,", "));
	cout<<endl;
	return 0;
}
