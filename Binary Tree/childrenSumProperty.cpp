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

void travserseTree(TreeNode* root){
    if(root == NULL) 
        return;
    
    cout << root->val << " ";
    travserseTree(root->left);
    travserseTree(root->right);
}

void changeTree(TreeNode* root){
    if(root == NULL) return;
    int child = 0;
    if(root->left != NULL) child += root->left->val;
    if(root->right != NULL) child += root->right->val;

    if(child >= root->val) root->val = child;
    else {
        if(root->left != NULL) root->left->val = root->val;
        if(root->right != NULL) root->right->val = root->val;
    }

    changeTree(root->left);
    changeTree(root->right);

    int tot = 0;
    if(root->left != NULL) tot += root->left->val; 
    if(root->right != NULL) tot += root->right->val; 
    if(root->left != NULL || root->right != NULL) root->val = tot; // not a leaf node in that case only will add left + right
    // in case of leaf node we don't change the value of the node
}
 

// TC - O(N)
// SC - O(N) 


int main(){
    TreeNode* root = new TreeNode(40);
    root->left = new TreeNode(10);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(30);
    root->right->right = new TreeNode(40);
    
    changeTree(root);

    travserseTree(root);
    
} 

