#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n=costs.size();
        if(!n)
            return 0;
        int pre0=costs[0][0];
        int pre1=costs[0][1];
        int pre2=costs[0][2];
        int cur0,cur1,cur2;
        for(int i=1;i<n;++i){
            cur0=min(pre1,pre2)+costs[i][0];
            cur1=min(pre0,pre2)+costs[i][1];
            cur2=min(pre0,pre1)+costs[i][2];
            pre0=cur0;
            pre1=cur1;
            pre2=cur2;
        }
        return min(pre0,min(pre1,pre2));
    }
};

int main(){

}
