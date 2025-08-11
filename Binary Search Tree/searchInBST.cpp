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
TreeNode* searchInBST(TreeNode* root, int target){
    if(root == NULL) return NULL;
    if(root->val == target) return root;
    if(root->val < target){
        searchInBST(root->right, target);
    }
    else searchInBST(root->left, target);
}

// TC - O(log2N)  log2N is the height of the tree
// SC - O(h) where 'h' represents the height of the tree


// This is strivers code
TreeNode* serachInBST(TreeNode* root, int target){
    while(root != NULL && root->val != target){
        root = target < root->val ? root->left : root->right;
    }
    return root;
}


int main(){
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(5);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(7);
    root->left->right->left = new TreeNode(6);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);

    int target = 6;
    TreeNode* node = searchInBST(root, target);

    if(node != NULL) cout << target << " Found in BTS";
    else cout << "Not found in BST";
   
    
    
} 

