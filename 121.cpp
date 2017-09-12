#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	int maxProfit(vector<int>& prices){
		int profit=0;
		int minValue=prices[0];
		for(int i=1;i<prices.size();++i){
			profit=max(profit,prices[i]-minValue);
			minValue=min(minValue,prices[i]);
		}
		return profit;
	}
};

int main(){
	vector<int> test={7,1,5,3,6,4};
	Solution s;
	cout<<s.maxProfit(test)<<endl;

	return 0;
}
