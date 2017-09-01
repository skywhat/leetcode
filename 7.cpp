#include<iostream>
#include<algorithm>

using namespace std;

class Solution{
public:
	int reverse(int x){
		int res=0;
		while(x){
			int digit=x%10;
			res=res*10+digit;
			x=x/10;
			if((res>INT_MAX/10&&x)||(res<INT_MIN/10&&x))
				return 0;
		}
		return res;
	}
};

int main(){
	Solution s;
	int x=-123;
	int x1=1534236469;
	cout<<s.reverse(x2)<<endl;

	return 0;
}
