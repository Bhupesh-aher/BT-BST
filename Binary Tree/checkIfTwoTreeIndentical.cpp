#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    public: 
    int val;
    TreeNode* left;
    TreeNode* right;

    public:
    TreeNode(int val1){
        val = val1;
        left = NULL;
        right = NULL;
    }
};

 bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == NULL && q == NULL) return true;
    if(p == NULL || q == NULL) return false;

    return ((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

// TC - O(N) 
// SC - O(N) 

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);


    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);


    if(isSameTree(root, root1)) cout << "Two trees are indentical";
    else cout << "Two trees are not indentical";
} 

