#include<iostream>
#include<string>
#include<sstream>

using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n,0);
        vector<pair<int,int>> t;
        int id,time;
        string state;
        stack<pair<int,int>> s;//pair id,start_time
        for(int i=0;i<logs.size();++i){
            istringstream in(logs[i]);
            in>>id;
            in>>state;
            if(state[1]=='s'){
                time=stoi(state.substr(7));
                state=state.substr(1,5);
            }
            else{
                time=stoi(state.substr(5));
                state=state.substr(1,3);
            }
            if(state=="start"){
                s.push({id,time});
            }
            else{
                int spent=time-s.top().second+1;
                res[id]+=spent;
                s.pop();
                if(!s.empty())
                    res[s.top().first]-=spent;
            }
            
        }
        return res;
        
    }
};


int main(){

}
