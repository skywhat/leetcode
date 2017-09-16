#include<iostream>


using namespace std;

class Solution{
public:
	bool isPalindrome(int x){
        if(x<10&&x>=0)
			return true;
		if(x<0||x%10==0)
			return false;
		int part=0;
		while(x>part){
			part=part*10+x%10;
			x/=10;
			if((x/10)==part)
				return true;
		}
		return part==x;
	}
};

int main(){
	Solution s;
	int x=2112;
	cout<<s.isPalindrome(x)<<endl;

	return 0;
}
