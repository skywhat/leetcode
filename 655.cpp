#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include "Tree.h"

using namespace std;

class Solution{
public:
    vector<vector<string>> printTree(TreeNode *root){
        int depth=0;
        queue<TreeNode*> q;
        if(root)
            q.push(root);
        while(!q.empty()){
            int size=q.size();
            while(size--){
                TreeNode* tmp=q.front();
                q.pop();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
            }
            depth++;
        }
        int width=1;
        for(int i=1;i<depth;++i){
            width=width*2+1;
        }
        vector<vector<string>> res(depth,vector<string>(width,"\"\""));
        if(root)
            q.push(root);
        int gap=width;
        int level=0;
        while(!q.empty()&&level<depth){
            gap=gap/2;
            int size=q.size();
            int pos=gap;
            while(size--){
                TreeNode* tmp=q.front();
                q.pop();
                if(tmp){
                    q.push(tmp->left);
                    q.push(tmp->right);
                }else{
                    q.push(NULL);
                    q.push(NULL);
                }
                if(tmp)
                    res[level][pos]="\""+to_string(tmp->val)+"\"";
                pos+=2*gap+2;
            }
            level++;
        }
        return res;
    }
};

int main(){
    TreeEnv t;
    vector<int> list={1,2,5,3,NULL_TREENODE,NULL_TREENODE,NULL_TREENODE,4,NULL_TREENODE};
    vector<int> list1={3,NULL_TREENODE,30,10,NULL_TREENODE,NULL_TREENODE,15,NULL_TREENODE,45};
    TreeNode* root=t.initialTree(list);
    Solution s;
    
    vector<vector<string>> res=s.printTree(root);
    for(int i=0;i<res.size();++i){
        for(int j=0;j<res[i].size();++j){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}

/*
 [3,null,30,10,null,null,15,null,45]
 
 [["","","","","","","","","","","","","","","","3","","","","","","","","","","","","","","",""],["","","","","","","","","","","","","","","","","","","","","","","","30","","","","","","",""],["","","","10","","","","","","","","","","","","","","","","","","","","","","","","","","",""],["","","","","","15","","","","","","","","","","","","","","","","","","","","","","","","",""],["","","45","","","","","","","","","","","","","","","","","","","","","","","","","","","",""]]
 
 
 [["","","","","","","","","","","","","","","","3","","","","","","","","","","","","","","",""],["","","","","","","","","","","","","","","","","","","","","","","","30","","","","","","",""],["","","","","","","","","","","","","","","","","","","","10","","","","","","","","","","",""],["","","","","","","","","","","","","","","","","","","","","","15","","","","","","","","",""],["","","","","","","","","","","","","","","","","","","","","","","45","","","","","","","",""]]
 */



