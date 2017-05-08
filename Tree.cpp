#include<iostream>
#include<vector>
#include<iterator>
#include<queue>
using namespace std;

#define NULL_TREENODE INT_MIN

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	TreeNode* initialTree(const vector<int>& treeList) {
			queue<TreeNode*> q;
			TreeNode* root;
			if (!treeList.empty()) {
						root = new TreeNode(treeList[0]);
						q.push(root);
					}
			else
				return NULL;
			int index = 1;
			while (!q.empty()) {
						TreeNode* tmp = q.front();
						q.pop();
						if (index < treeList.size()) {
										if (treeList[index] != NULL_TREENODE) {
															tmp->left = new TreeNode(treeList[index]);
															q.push(tmp->left);
														}
										index++;
									}
						if (index < treeList.size()) {
										if (treeList[index] != NULL_TREENODE) {
															tmp->right = new TreeNode(treeList[index]);
															q.push(tmp->right);
														}
										index++;
									}
					}
			return root;
		}
	void displayTree(TreeNode* root) {
			queue<TreeNode*> q;
			if (root) {
						q.push(root);
						cout << root->val << endl;
					}
			while (!q.empty()) {
						int size = q.size();
						while (size--) {
										TreeNode* tmp = q.front();
										q.pop();
										if (tmp->left) {
															q.push(tmp->left);
															cout << tmp->left->val << " ";
														}
										if (tmp->right) {
															q.push(tmp->right);
															cout << tmp->right->val << " ";
														}
									}
						cout << endl;
					}
		}
};

int main() {
	vector<int> treeList = {1,2,5,3,4,INT_MIN,6};
	Solution s;
	TreeNode* root = s.initialTree(treeList);
	s.displayTree(root);

	return 0;
}

