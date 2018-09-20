/*
Let's suppose Bloomberg is sponsoring a coding competition at its New York and
San Francisco offices. We will have to fly the participants to either one of
these two offices. Each office can only accommodate half of the participants.
The goal is to assign each participant to an office in a way that the total
travel cost for the company is minimized. Each participant will be represented
as a pair of costs: <costToFlyToNY, costToFlyToSF>
Determine the minimum cost given a list of participants.

Participant List as <costToFlyToNY, costToFlyToSF>:
<500, 600>, person 0
<600, 400>, person 1
<200, 900>, person 2. visit 1point3acres for more.
<700, 300>, person 3

Output: 1400
*/

/*
-100 person 0 => 500
200  person 1 => 400
-700 person 2 => 200
400 person 4 => 300
total => 1400
*/


#include <iostream>
#include <queue>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    struct comp{
        bool operator()(const pair<int, int>& l, const pair<int, int>& r){
            return l.second < r.second;
        }
    };

    int minCost(vector<vector<int>> cost_list) {
        int k = cost_list.size()/2;
        int min_cost = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> q;
        for(int i=0; i<cost_list.size(); ++i){
            q.push({i, cost_list[i][0]-cost_list[i][1]});
            if(q.size() > k){
                auto temp = q.top();
                q.pop();
                min_cost += cost_list[temp.first][1];
            }
        }

        while(!q.empty()){
            auto temp = q.top();
            q.pop();
            min_cost += cost_list[temp.first][0];
        }

        return min_cost;
    }
};

int main() {
    vector<vector<int>> test = {
        {500, 600},
        {600, 400},
        {200, 900},
        {700, 300},
    };

    Solution s;
    cout << (s.minCost(test) == 1400) << endl;

    return 0;
}
