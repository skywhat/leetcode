#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(num,target,res,"",0,0,0);
        return res;
    }
    void dfs(const string& num,const int& target,vector<string>& res,string path,int pos,long val,long multi){
        if(pos==num.size()){
            if(target==val)
                res.push_back(path);
            return;
        }
        for(int i=1;i+pos<=num.size();++i){
            string curNum=num.substr(pos,i);
            if(i>=2&&curNum[0]=='0')
                break;
            long cur=stol(curNum);
            if(pos==0){
                dfs(num,target,res,path+curNum,pos+i,cur,cur);
            }else{
                dfs(num,target,res,path+"+"+curNum,pos+i,val+cur,cur);
                dfs(num,target,res,path+"-"+curNum,pos+i,val-cur,-cur);
                dfs(num,target,res,path+"*"+curNum,pos+i,val-multi+multi*cur,multi*cur);
            }
        }
    }
};

int main(){
	string num="3456237049";
	int target=43;
	Solution s;
	vector<string> res=s.addOperators(num,target);
	for(auto r:res)
		cout<<r<<endl;

	return 0;
}



