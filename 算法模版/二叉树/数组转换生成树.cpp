#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *lchild;
    TreeNode *rchild;
    TreeNode(): val(0), lchild(NULL), rchild(NULL) {} 
    TreeNode(int x):val(x), lchild(NULL), rchild(NULL) {}
};

TreeNode* ArrayToTree(vector<int>& arr, int idx) {

    if (idx >= arr.size() || arr[idx] == 0) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(arr[idx]);

    root->lchild = ArrayToTree(arr, 2*idx + 1);

    root->rchild = ArrayToTree(arr, 2*idx + 2);
    return root;
}

void print1(TreeNode* root){
    if(root == NULL) {
        return;
    }
    cout << root->val << " ";
    print1(root->lchild);
    print1(root->rchild);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
    cin >> n;
    vector<int> ret(n);
    for (int i = 0; i < n;++i){
        cin >> ret[i];
    }
    TreeNode *root = ArrayToTree(ret, 0);
    print1(root);
    cout << endl;
    }
    
    return 0;
}