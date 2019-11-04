#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	int maxProfit(vector<int>& prices,int fee){
		int s0=0,s1=INT_MIN;
		for(auto p:prices){
			int tmp=s0;
			s0=max(s0,s1+p);
			s1=max(s1,tmp-p-fee);
		}
		return s0;
	}
};	

int main(){
	vector<int> test={1,3,2,8,4,9};
	int fee=2;
	Solution s;
	cout<<s.maxProfit(test,fee)<<endl;

	return 0;
}


/*
s0 profit having no stock
s1 profit having one stock
fee=2
    stock    1   3  2  8  4  9
    index    0   1  2  3  4  5
    tmp  0   0   0  0  0  5  5
    s0   0   0   0  0  5  5  8
    s1   M  -3  -3 -3 -3  -1 -1

    =>s0 =8 the last moment we have no stock in hand.
*/
