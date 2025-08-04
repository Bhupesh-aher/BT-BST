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

bool symmetric(TreeNode* left, TreeNode* right){
    if(left == NULL && right == NULL) return true;
    if(left == NULL || right == NULL) return false;
    if(left->val != right->val) return false;
    return symmetric(left->left, right->right) && symmetric(left->right, right->left);
    
}
bool isSymmetric(TreeNode* root) {
    if(root == NULL) return true;
    return symmetric(root->left, root->right); 
}

// TC - O(N)
// SC - O(N)  

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    
    cout << isSymmetric(root);

    
} 

