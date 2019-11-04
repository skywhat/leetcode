#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int len=s.size();
        int i=0,j=0,l;//j is on the right, i is one the left
        int wordcount=0;
        while(true){
            while(s[j]==' ')//skip the leading spaces
                j++;
            if(j==len)
                break;
            if(wordcount)//add one space
                s[i++]=' ';
            l=i;
            while(j<len&&s[j]!=' '){
                s[i]=s[j];
                i++;
                j++;
            }
            reverse(s,l,i-1);//reverse the part string
            wordcount++;
        }
        s.resize(i);//resize the result string
        reverse(s,0,i-1);//reverse whole string
        
    }
    void reverse(string& s,int i,int j){
        while(i<j){
            char x=s[i];
            s[i]=s[j];
            s[j]=x;
            i++;
            j--;
        }
    }
};

int main(){
	Solution s;
	string test="  the sky is blue ";
	s.reverseWords(test);
	cout<<test<<endl;

	return 0;

}

