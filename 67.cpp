#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        if(a == "0"){
            return b;
        }
        if(b == "0"){
            return a;
        }
        
        string res;
        int i=a.size()-1, j=b.size()-1;
        int carry = 0;
        while(i>=0 || j>=0 || carry){
            int digit = (i>=0? a[i--]-'0':0) + (j>=0? b[j--]-'0':0) + carry;
            res = to_string(digit%2) + res;
            carry = digit/2;
        }
        
        return res;
    }
};

int main(){
	string a="11";
	string b="1";

	Solution s;
	cout<<s.addBinary(a,b)<<endl;

	return 0;

}



