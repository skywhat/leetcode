#include<iostream>
#include<vector>
#include "Tree.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        bool rightToleft=false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int> row(size);
            for(int i=0;i<size;++i){
                TreeNode* temp=q.front();
                q.pop();
                row[rightToleft?(size-i-1):i]=temp->val;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            res.push_back(row);
            rightToleft=!rightToleft;
        }
        return res;
        
    }
};

int main(){
	TreeEnv t;
	vector<int> test={3,9,20,NULL_TREENODE,NULL_TREENODE,15,7};
	TreeNode* root=t.initialTree(test);

	Solution s;
	vector<vector<int>> res=s.zigzagLevelOrder(root);
	for(auto row:res){
		cout<<"[";
		for(auto elem: row){
			cout<<elem<<", ";
		}
		cout<<"]"<<endl;

	}
	
	return 0;
	
}
