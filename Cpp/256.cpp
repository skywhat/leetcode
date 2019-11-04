#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.empty()){
            return 0;
        }
        
        int pre0 = costs[0][0];
        int pre1 = costs[0][1];
        int pre2 = costs[0][2];
        
        int cur0=0, cur1=0, cur2=0;
        for(int i=1; i<costs.size(); ++i){
            cur0 = costs[i][0] + min(pre1, pre2);
            cur1 = costs[i][1] + min(pre0, pre2);
            cur2 = costs[i][2] + min(pre0, pre1);
            
            pre0 = cur0;
            pre1 = cur1;
            pre2 = cur2;
        }
        
        return min(min(pre0, pre1), pre2);
    }
};

int main(){

}
