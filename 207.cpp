#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution{
public:
    bool canFinish(int numCourses,vector<pair<int,int>>& prerequisites){
        vector<int> degree(numCourses,0);
        for(auto x:prerequisites){
            degree[x.second]++;
        }
        stack<int> s;// queue is also okay
        for(size_t i=0;i<degree.size();++i){
            if(degree[i]==0){
                s.push(i);
            }
        }
        int cnt=0;
        while(!s.empty()){
            int cur=s.top();
            s.pop();
            cnt++;//how many node we have stored.
            for(auto &x:prerequisites){
                if(x.first==cur){
                    x.first=-1;// we will never find x.first later.
                    if(--degree[x.second]==0){
                        s.push(x.second);
                    }
                }
            }
        }
        return cnt==numCourses;
    }
};

int main(){
	Solution s;
	vector<pair<int,int>> pre={{1,0}};
	int numCourses=2;
	cout<<s.canFinish(numCourses,pre)<<endl;

	return 0;
}



