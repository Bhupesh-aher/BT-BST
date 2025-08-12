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

void printPreorder(TreeNode* root){
    if(root == NULL) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL) return new TreeNode(val);
    TreeNode* curr = root;
    while(true){
        if(curr->val <= val){
            if(curr->right != NULL) curr = curr->right;
            else {
                curr->right = new TreeNode(val);
                break;
            }
        }
        else {
            if(curr->left != NULL) curr = curr->left;
            else {
                curr->left = new TreeNode(val);
                break;
            }
        }
    }
    return root;
}

// TC - O(log2N)  log2N is the height of the tree
// SC - O(h) where 'h' represents the height of the tree



int main(){
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(3);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(7);

    int val = 5;
    TreeNode* root1 = insertIntoBST(root, val);

    printPreorder(root1);

} 

