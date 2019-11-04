#include<iostream>
#include<bitset>
#include<vector>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        bitset<200001> kinds;
        for(auto kind: candies){
            if(!kinds.test(kind+100000)){
                kinds.set(kind+100000);
            }
        }
        return min(kinds.count(), candies.size()/2);
    }
};

int main(){
	vector<int> candies={1,1,2,2,3,3};
	int expect = 3;
	Solution s;
	cout<<(s.distributeCandies(candies) == expect) <<endl;

	return 0;	
}
