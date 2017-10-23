#include<iostream>
#include<map>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>> point,res;
        for(auto b:buildings){
            point.push_back({b[0],-b[2]});
            point.push_back({b[1],b[2]});
        }
        sort(point.begin(),point.end(),[](pair<int,int> i, pair<int,int> j){
            if(i.first==j.first)
                return i.second<j.second;
            return i.first<j.first;
        });
        multiset<int> m;
        m.insert(0);
        int curH=0,prevH=0;
        for(int i=0;i<point.size();++i){
            if(point[i].second<0){
                m.insert(-point[i].second);
            }
            else
                m.erase(m.find(point[i].second));
            int curH=*m.rbegin();
            if(curH!=prevH){
                res.push_back({point[i].first,curH});
            }
            prevH=curH;
        }
        return res;
    }
};

int main(){
}
