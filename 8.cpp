#include<iostream>
#include<string>

using namespace std;

class Solution{
public:
	int myAtoi(string str){
		int sign=1;
		long long sum=0;
		int i=0;
		while(str[i]==' ')
			i++;
		if(str[i]=='-'||str[i]=='+')){
			if(str[i]=='-')
				sign=-1;	
			i++;
		}
			while(str[i]<='9'&&str[i]>='0'){
				sum=sum*10+sign*(str[i++]-'0');
				if(sum>=INT_MAX)
					return INT_MAX;
				else if(sum<=INT_MIN)
					return INT_MIN;
			}
		return int(sum);
	}
};

int main(){
	string str="+-2";
	Solution s;
	cout<<s.myAtoi(str)<<endl;
	return 0;
}
