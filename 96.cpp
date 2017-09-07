#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	int numTrees(int n){
		vector<int> res(n+1,0);
		if(n>=1){
			res[0]=1;
			res[1]=1;
		}
		for(int i=2;i<=n;++i){
			for(int j=0;j<=i-1;++j){
				res[i]+=res[j]*res[i-1-j];
			}
		}
		return res[n];
	}
};

int main(){
	Solution s;
	int n=3;
	cout<<s.numTrees(n)<<endl;

	return 0;
}
