//Give the lowest common ancestor of all the deepest nodes of a tree

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct TreeNode{
    int val;
    vector<TreeNode*> children;
    TreeNode(int x):val(x),children(vector<TreeNode*>()){}
};

void printTree(TreeNode* root){
    if(!root)
    return;
    cout<<root->val<<", ";
    for(auto kid:root->children)
    printTree(kid);
}

class Solution{
    public:
    TreeNode* LCA(TreeNode* root){
        if(!root)
            return nullptr;
        TreeNode* res;
        depth(root,res);
        return res;
    }
    int depth(TreeNode* root,TreeNode* &res){
        //when node is leaf, itself is the deepest node and its ancestor is NULL(because it has no parent
        if(root->children.empty()){
            res=nullptr;
            return 0;
        }
        TreeNode* tmp=nullptr;
        
        int max_depth=0;
        //count the number of neighbors with largest depth
        int cnt=1;
        //traverse all the children of current node
        for(auto kid:root->children){
            TreeNode* sub_res=nullptr;
            int sub_depth=depth(kid,sub_res)+1;
            if(sub_depth>max_depth){
                cnt=1;
                max_depth=sub_depth;
                //this kid is a leaf. the LCA would be root.
                if(sub_res==nullptr)
                    tmp=root;
                else
                    tmp=sub_res;
            }
            else if(sub_depth==max_depth)
                cnt++;
        }
        //cnt=1. the root's division has only one deepest path.
        if(cnt==1)
            res=tmp;
        else
            res=root;
        return max_depth;
    }
};
TreeNode* generate(){
    TreeNode* root=new TreeNode(1);
    root->children.push_back(new TreeNode(2));
    root->children.push_back(new TreeNode(3));
    root->children.push_back(new TreeNode(4));
    root->children.push_back(new TreeNode(5));
    
    root->children[0]->children.push_back(new TreeNode(6));
    root->children[0]->children.push_back(new TreeNode(7));
    root->children[0]->children.push_back(new TreeNode(8));
    
    root->children[1]->children.push_back(new TreeNode(9));
    root->children[1]->children.push_back(new TreeNode(10));
    
    root->children[2]->children.push_back(new TreeNode(11));
    root->children[3]->children.push_back(new TreeNode(12));
    
    return root;
}

/*
 
                 1
    2       3       4       5
 6 7 8    9  10    11       12
 
 
 */
int main(){
    Solution s;
    TreeNode* root=generate();
    TreeNode* res=s.LCA(root);
    
    cout<<"CAD node: "<<res->val<<endl;
    
    cout<<"\nadd node 13 to node 6"<<endl;
    root->children[0]->children[0]->children.push_back(new TreeNode(13));
    res=s.LCA(root);
    cout<<"CAD node: "<<res->val<<endl;
    
    cout<<"\nadd node 14 to node 7"<<endl;
    root->children[0]->children[1]->children.push_back(new TreeNode(14));
    res=s.LCA(root);
    cout<<"CAD node: "<<res->val<<endl;
    
    cout<<"\nadd node 15 to node 12"<<endl;
    root->children[3]->children[0]->children.push_back(new TreeNode(15));
    res=s.LCA(root);
    cout<<"CAD node: "<<res->val<<endl;
    
    printTree(root);
    
    return 0;
    
}




//http://www.1point3acres.com/bbs/thread-148413-1-1.html
