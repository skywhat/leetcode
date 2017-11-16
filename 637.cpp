#include<iostream>
#include<queue>
#include<iterator>
#include "Tree.h"

using namespace std;

//BFS
class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> v;
		queue<TreeNode*> q;
		if (root) {
			q.push(root);
		}
		while (!q.empty()) {
			int size = q.size();
			double sum = 0;
			int count = 0;
			while (size--) {
				TreeNode* tmp = q.front();
				sum += tmp->val;
				count++;
				q.pop();
				if (tmp->left) {
					q.push(tmp->left);
				}
				if (tmp->right) {
					q.push(tmp->right);
				}
			}
			v.push_back(sum/count);
		}
		return v;
	}
};

//recursive DFS
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        map<int,pair<int,double>> m;
        vector<double> res;
        preorder(root,m,0);
        for(auto item:m){
            res.push_back(item.second.second/item.second.first);
        }
        return res;
        
    }
    void preorder(TreeNode* root,map<int,pair<int,double>>& m,int level){
        if(root){
            if(m.find(level)==m.end()){
                m[level]=make_pair(1,root->val);
            }
            else{
                m[level].first++;
                m[level].second+=root->val;
            }
            preorder(root->left,m,level+1);
            preorder(root->right,m,level+1);
        }
    }
};

int main() {
	TreeEnv t;
	vector<int> list = {4,2,7,1,3,6,9};
	TreeNode* root=t.initialTree(list);
	t.displayTree(root);

	Solution s;
	
	vector<double> v = s.averageOfLevels(root);
	copy(v.begin(), v.end(), ostream_iterator<double>(cout, ", "));

	return 0;
}

