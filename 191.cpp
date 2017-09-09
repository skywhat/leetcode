#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	int hammingWeight(uint32_t n){
		int cnt=0;
		for(int i=0;i<32;++i){
			if((n>>i)&1)
				cnt++;
		}
		return cnt;
	}
};

class Solution1{
	public:
		int hammingWeight(uint32_t n){
			int cnt=0;
			while(n){
				cnt++;
				n&=n-1;
			}
			return cnt;
		}
};

int main(){
	unsigned n=11;
	Solution s;
	cout<<s.hammingWeight(n)<<endl;

	return 0;
}
