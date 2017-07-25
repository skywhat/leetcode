#include<iostream>
#include<queue>
#include<iterator>
#include "Tree.h"

using namespace std;

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

