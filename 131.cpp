#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        partition(s,res,temp,0);
        return res;
    }
    void partition(string s,vector<vector<string>>& res,vector<string>& temp,int ind){
        if(ind>=s.size())
            return;
        if(valid(s)&&ind==0){
            temp.push_back(s);
            res.push_back(temp);
            temp.pop_back();
        }
        string left=s.substr(0,ind+1);
        if(valid(left)){
            temp.push_back(left);
            partition(s.substr(ind+1),res,temp,0);
            temp.pop_back();
        }
        partition(s,res,temp,ind+1);
    }
    bool valid(const string& s){
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
};
/*
 aaa
 012
 */

int main(){
	string test="aaa";
	Solution s;
	auto res=s.partition(test);
	for(auto row:res){
		cout<<"[";
		for(auto elem:row){
			cout<<elem<<", ";
		}
		cout<<"]"<<endl;
	}

	return 0;
}


