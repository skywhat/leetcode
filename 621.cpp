#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<map>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> t(26,0);
        for(auto name:tasks){
            t[name-'A']++;
        }
        sort(t.begin(),t.end());
        int maxNum=t[25];
        int i=25;
        for(;i>=0&&t[i]==t[25];--i);
        int predict=(t[25]-1)*(n+1)+25-i;
        int actual=tasks.size();
        return max(actual,predict);
    }
};

int main(){

}
