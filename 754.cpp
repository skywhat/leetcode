#include<iostream>
#include<cmath>

using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        target=abs(target);
		//(-b+sqrt(b^2-4*a*c))/(2*a)
		//n^2+n-2*target=0
        //8*target might overflow
 		long long n=ceil((-1+sqrt(1+8.0*target))/2);
		long long sum=n*(n+1)/2;
		if(sum==target)
			return n;
		long long res=sum-target;
		if((res&1)==0)
			return n;
		return (n&1)?n+2:n+1;
    }
};

/*
4
1 2 3 =6>4
res=6-4=2



*/
