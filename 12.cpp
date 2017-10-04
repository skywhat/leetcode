#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	string intToRoman(int num){
		string res;
		vector<int> divisor={1000,900,500,400,100,90,50,40,10,9,5,4,1};
		vector<string> RomanN={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};	
		for(int i=0;i<divisor.size();++i){
			int c=num/divisor[i];
			while(c--){
				res+=RomanN[i];
			}
			num%=divisor[i];
		}	
		return res;
	}	
};

int main(){
	int n=3;
	Solution s;
	cout<<s.intToRoman(n)<<endl;

	return 0;
}
