#include<iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1){
            return x;
        }
        
        int i=0,j=x;
        while(i+1 < j){
            int mid = i + (j-i)/2;
            if(mid < x/mid){
                i = mid;
            }
            else{
                j = mid;
            }
        }
        
        return j <= x/j? j:i;
    }
};

int main(){
	int x=10;
	Solution s;
	cout<<s.mySqrt(x)<<endl;

	return 0;
}


