#include<iostream>
#include<vector>

using namespace std;

struct TreeLinkNode{
	int val;
	TreeLinkNode* next,*left,*right;
	TreeLinkNode(int x):val(x),left(NULL),right(NULL),next(NULL){}
};

class Solution{
public:
	typedef TreeLinkNode tln;
	void connect(TreeLinkNode *root){
		tln *cur=root;
		tln *head=nullptr;
		tln *prev=nullptr;
		while(cur){
			while(cur){
				if(cur->left){
					if(prev==nullptr)
						head=cur->left;
					else
						prev->next=cur->left;
					prev=cur->left;
				}
				if(cur->right){
					if(prev==nullptr)
						head=cur->right;
					else
						prev->next=cur->right;
					prev=cur->right;
				}
				cur=cur->next;//move to next node
			}
			cur=head;//move to next level
			head=nullptr;
			prev=nullptr;
		
		}
	}
};

int main(){

}
