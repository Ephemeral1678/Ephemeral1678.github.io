#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
	char val;
	TreeNode* lchild;
	TreeNode* rchild;
	TreeNode() : val(0), lchild(NULL), rchild(NULL) {}
};

//先序遍历构建树
TreeNode* buildTree(){
	char c;
	cin >> c;
	if(c == '#'){
		return NULL;
	}
	TreeNode *root = new TreeNode();
	root->val = c;
	root->lchild = buildTree();
	root->rchild = buildTree();

	return root;
}

//先序遍历
void print1(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	cout << root->val;
	print1(root->lchild);
	print1(root->rchild);
}

//中序遍历
void print2(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	print2(root->lchild);
	cout << root->val;
	print2(root->rchild);
}

//后序遍历
void print3(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	print3(root->lchild);
	print3(root->rchild);
	cout << root->val;
}

//层次遍历
void print4(TreeNode* root){
	if(root == NULL){
		return;
	}
	queue<TreeNode *> q;
	q.push(root);
	while(!q.empty()){
		TreeNode *current = q.front();
		q.pop();
		cout << current->val;
		if(current->lchild != NULL){
			q.push(current->lchild);
		}
		if(current->rchild != NULL){
			q.push(current->rchild);
		}
	}
}

//求树的深度
int getDepth(TreeNode* root){
	if(root == NULL){
		return 0;
	}
	int ldepth = getDepth(root->lchild);
	int rdepth = getDepth(root->rchild);
	return max(ldepth, rdepth) + 1;
}

//求叶子结点
void getLeaves(vector<TreeNode*> &leaves, TreeNode* root){
	if(root == NULL){
		return ;
	}
	if(root->lchild == NULL && root->rchild == NULL){
		leaves.push_back(root);
	}
	getLeaves(leaves, root->lchild);
	getLeaves(leaves, root->rchild);
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		TreeNode *root = buildTree();
		print1(root);
		cout << endl;
		print2(root);
		cout << endl;
		print3(root);
		cout << endl;
	}
	return 0;
}