#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;


struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode *> neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    typedef UndirectedGraphNode ugn;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node)
            return nullptr;
        unordered_map<ugn*,ugn*> m;
        queue<ugn*> q;
        ugn* copy=new ugn(node->label);
        m[node]=copy;
        q.push(node);
        while(!q.empty()){
            ugn* tmp=q.front();
            q.pop();
            for(auto nb:tmp->neighbors){
                if(m.find(nb)==m.end()){
                    ugn* one=new ugn(nb->label);
                    m[nb]=one;
                    q.push(nb);
                }
                m[tmp]->neighbors.push_back(m[nb]);
            }
        }
        return copy;
    }
};
