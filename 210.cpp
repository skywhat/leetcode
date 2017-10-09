#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> degree(numCourses,0);
        for(auto x:prerequisites){
            degree[x.first]++;
        }
        stack<int> s;
        for(size_t i=0;i<degree.size();++i)
        if(degree[i]==0)
        s.push(i);
        vector<int> toposort;
        int cnt=0;
        while(!s.empty()){
            int cur=s.top();
            s.pop();
            cnt++;
            toposort.push_back(cur);
            for(auto& x:prerequisites){
                if(x.second==cur){
                    x.second=-1;
                    if(--degree[x.first]==0)
                    s.push(x.first);
                }
            }
        }
        return cnt==numCourses?toposort:vector<int>();
    }
};

int main(){
    vector<pair<int,int>> pre={{1,0},{2,0},{3,1},{3,2}};
    int numCourses=4;
    Solution s;
    vector<int> res=s.findOrder(numCourses,pre);
    for(auto c:res){
        cout<<c<<" -> ";
    }
    cout<<endl;
    return 0;
}


