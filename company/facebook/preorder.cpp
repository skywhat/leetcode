/*
 Construct BST from given preorder traversal
 preorder: 10 5 1 7 40 50
 
              10
         5         40
      1      7          50
 
 */



class Solution{
public:
    TreeNode* buildBST(vector<int>& preorder){
		int pos=0;
        return build(preorder,pos,preorder[0],INT_MIN,INT_MAX);
    }
    TreeNode* build(const vector<int>& preorder,int& pos,int key,int min, int max){
        if(pos>=preorder.size())
            return nullptr;
        if(key>min&&key<max){
            TreeNode* root=new TreeNode(key);
            pos++;
            if(pos<preorder.size()){
                root->left=build(preorder,pos,preorder[pos],min,key);
                root->right=build(preorder,pos,preorder[pos],key,max);
            }
            return root;
        }
        return nullptr;
    }
};

int main(){

}
