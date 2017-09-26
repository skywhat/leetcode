#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// NULL节点标示
#define NULL_TREENODE INT_MIN

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {}
};

class TreeEnv {
public:
	//输入vector<int> 树层序遍历的节点，NULL空节点以NULL_TREENODE表示
	//返回TreeNode* 根节点
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

	//Convert an array where elements are sorted in ascending order to binary search tree
	TreeNode* initialBinarySearchTree(const vector<int>& treeList) {
		if (!treeList.empty()) {
			return initialBinarySearchTree(treeList, 0, treeList.size() - 1);
		}
		else
			return NULL;
	}
	TreeNode* initialBinarySearchTree(const vector<int>& treeList, int left, int right) {
		if (left > right)
			return NULL;
		if (left == right) {
			return new TreeNode(treeList[left]);
		}
		int mid = (left + right) / 2;
		TreeNode* root = new TreeNode(treeList[mid]);
		root->left = initialBinarySearchTree(treeList, left, mid - 1);
		root->right = initialBinarySearchTree(treeList, mid + 1, right);
		return root;
	}

	//层序遍历方式输出树root，无法显示出父子节点的关系，有待改进
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
	
	void inOrder(TreeNode* root){
		if(root){
			inOrder(root->left);
			cout<<root->val<<", ";
			inOrder(root->right);
		}	
	}

	void preOrder(TreeNode* root){
		if(root){
			cout<<root->val<<", ";
			preOrder(root->left);
			preOrder(root->right);
		}
	}

	void postOrder(TreeNode* root){
		if(root){
			postOrder(root->left);
			postOrder(root->right);
			cout<<root->val<<", ";
		}
	}

};



