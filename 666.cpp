#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
#include "Tree.h"

using namespace std;


class Solution {
private:
    struct TreeNode{
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    };
public:
    int pathSum(vector<int>& nums) {
        map<pair<int,int>,int> m;
        for(auto n:nums){
            int x=n/100;
            int y=n%100/10;
            int pos=n%10;
            pair<int,int> p=make_pair(x,y);
            m[p]=pos;
        }
        TreeNode* root=construct(m,1,1);
		//TreeEnv t;
		//t.displayTree(root);
        int sum=0;
        path(root,0,sum);
        return sum;
    }
    TreeNode* construct(const map<pair<int,int>,int>& m,int x,int y){
        TreeNode* root=nullptr;
        pair<int,int> p=make_pair(x,y);
        auto it=m.find(p);
        if(it!=m.end()){
            root=new TreeNode(it->second);
            root->left=construct(m,x+1,2*y-1);
            root->right=construct(m,x+1,2*y);
        }
        return root;
    }
    void path(TreeNode* root,int pathsum,int& sum){
        if(root){
            pathsum+=root->val;
            if(!root->left&&!root->right)
            sum+=pathsum;
            else{
                path(root->left,pathsum,sum);
                path(root->right,pathsum,sum);
            }
            
        }
    }
};

class Solution2 {
public:
    int pathSum(vector<int>& nums) {
        map<pair<int,int>,int> m;
        for(auto n:nums){
            int x=n/100;
            int y=n%100/10;
            int val=n%10;
            m[make_pair(x,y)]=val;
        }
        int sum=0;
        path(m,1,1,0,sum);
        return sum;
    }
    void path(const map<pair<int,int>,int> m,int x,int y,int pathsum,int& sum){
        pair<int,int> p=make_pair(x,y);
        auto it=m.find(p);
        if(it!=m.end()){
            pathsum+=it->second;
            if(m.find(make_pair(x+1,2*y-1))==m.end()&&m.find(make_pair(x+1,2*y))==m.end()){
                sum+=pathsum;
            }
            else{
                path(m,x+1,2*y-1,pathsum,sum);
                path(m,x+1,2*y,pathsum,sum);
            }
        }
    }
};

int main(){
    vector<int> test={115,215,224,325,336,446,458};
    
    Solution s;
    cout<<s.pathSum(test)<<endl;
    
    return 0;
}
