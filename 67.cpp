#include<iostream>
#include<string>

using namespace std;

class Solution{
public:
	string addBinary(string a,string b){
		int i=a.size()-1,j=b.size()-1;
		string c;
		int carry=0;
		while(i>=0||j>=0||carry==1){
			int m=i>=0?a[i]-'0':0;
			int n=j>=0?b[j]-'0':0;
			int sum=m+n+carry;
			c=(sum%2?"1":"0")+c;
			carry=sum/2;
			i--;
			j--;
		}
		return c;
	}	
};

int main(){
	string a="11";
	string b="1";

	Solution s;
	cout<<s.addBinary(a,b)<<endl;

	return 0;

}



