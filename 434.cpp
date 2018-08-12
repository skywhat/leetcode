#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
public:
	int countSegments(string s){
		int cnt=0;
		int i=0;
		while(i<s.size()){
			if(s[i]!=' '){
				while(i<s.size() && s[i]!=' '){
                    i++;
                }
				cnt++;
			}
			while(i<s.size() && s[i]==' '){
                i++;
            }
		}
		return cnt;
	}
};

class Solution2 {
public:
    int countSegments(string s) {
        int cnt = 0;
        s.push_back(' ');
        for(int i=1;i<s.size();++i){
            if(s[i-1]!=' ' && s[i]==' '){
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){
	string test="Hello, my name is John";
	string test1="love live! mu'sic forever";
	Solution s;
	cout<<s.countSegments(test1)<<endl;

	return 0;
}
