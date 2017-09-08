#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
public:
	string convert(string s,int numRows){
		if(numRows==1)
			return s;
		int width=2*numRows-2;
		vector<int> index(s.size(),0);
		int pos=0;
		for(int i=1;i<=numRows;++i){
			if(i==1||i==numRows){
				for(int j=i;j<=s.size();j+=width)
					index[pos++]=j;
			}
			else{
				int sep1=width-2*i+2;
				int sep2=width-sep1;
				vector<int> sep={sep1,sep2};
				int j=i,cnt=0;
				while(j<=s.size()){
					index[pos++]=j;
					j+=sep[cnt%2];
					cnt++;
				}
			}
		}
		string res;
		for(int i=0;i<index.size();++i){
			res+=s[index[i]-1];
		}
		return res;
	}
};

int main(){
	string test="PAYPALISHIRING";
	string test1="ABCDE";
	Solution s;
	int numRows=3;
	cout<<s.convert(test,numRows)<<endl;

	return 0;

}
