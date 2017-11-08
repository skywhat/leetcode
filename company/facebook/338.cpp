#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> res(num+1,0);
		for(int n=1;n<=num;++n)
			res[n] = res[n >> 1] + (1 & n);
		return res;

	}
};
