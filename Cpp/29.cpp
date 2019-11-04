#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	int divide(int dividend, int divisor){
		//the only case which will overflow.
		if(dividend==INT_MIN&&divisor==-1)
			return INT_MAX;
		int sign=(dividend>0)^(divisor>0)?0:1;
		long long dd=labs(dividend);
		long long dr=labs(divisor);
		int ans=0;
		while(dd>=dr){
			int i=0;
			while((dd-(dr<<i))>=0)
				i++;
			ans+=(1<<(i-1));
			dd-=(dr<<(i-1));
		}
		return sign?ans:-ans;
	}
};

int main(){
	Solution s;
	int dd=15,dr=3;
	int dd1=-1,dr1=1;
	cout<<s.divide(dd1,dr1)<<endl;

	return 0;
}
