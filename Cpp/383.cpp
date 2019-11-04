#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> dict(128, 0);
        for(auto c: magazine){
            dict[c]++;
        }
        for(auto c: ransomNote){
            if(--dict[c] < 0){
                return false;
            }
        }  
        return true;
    }
};

int main(){
	string ransomNote="aa";
	string magazine="aab";
	Solution s;
	cout<<s.canConstruct(ransomNote,magazine)<<endl;

	return 0;
}
