#include<iostream>

using namespace std;

class Solution{
public:
	double myPow(double x,int n){
		if(n==0)
			return 1;
		if(n==1)
			return x;
		int ex=n/2;
		if(n<0){
			ex=-ex;
			x=1/x;
		}
		return n%2?x*myPow(x*x,ex):myPow(x*x,ex);
	}
};

int main(){
	Solution s;
	double x=2.0;
	int n=-1;
	cout<<s.myPow(x,n)<<endl;

	return 0;
}
