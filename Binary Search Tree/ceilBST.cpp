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


// This is my code
int ceilInBST(TreeNode* root, int &ceil, int key){
    if(root == NULL) return ceil;
    if(root->val >= key) {
        ceil = root->val;
        ceilInBST(root->left, ceil, key);
    }
    else ceilInBST(root->right, ceil, key);
}

// TC - O(log2N)  log2N is the height of the tree
// SC - O(h) where 'h' represents the height of the tree



// This is strivers code
int ceilInBST(TreeNode* root, int key){
    int ceil = -1;
    while(root != NULL){
        if(root->val == key) {
            ceil = root->val;
            return ceil;
        }

        if(key > root->val){
            root = root->right;
        }
        else {
            ceil = root->val;
            root = root->left;
        }
    }
    return ceil;
}

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(6);
    root->left->left->left = new TreeNode(2);
    root->left->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(14);

    int ceil = -1;
    int key = 8;
    cout << ceilInBST(root, ceil, key);
    
} 

