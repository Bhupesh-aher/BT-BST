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

TreeNode* findLastRight(TreeNode* root){
    if(root->right == NULL) return root;
    return findLastRight(root->right);
}
TreeNode* helper(TreeNode* root){
    if(root->left == NULL) return root->right;
    else if(root->right == NULL) return root->left;
    TreeNode* rightChild = root->right;
    TreeNode* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}
TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == NULL) return NULL;
    if(root->val == key){
        return helper(root);
    }   
    TreeNode* dummy = root;
    while(root != NULL){
        if(root->val > key){
            if(root->left != NULL && root->left->val == key){
                root->left = helper(root->left);
                break;
            }
            else {
                root = root->left;
            }
        }
        else {
            if(root->right != NULL && root->right->val == key){
                root->right = helper(root->right);
                break;
            }
            else {
                root = root->right;
            }
        }
    }
    return dummy;
}

// TC - O(log2N)  log2N is the height of the tree
// SC - O(h) where 'h' represents the height of the tree



int main(){
    TreeNode* root = new TreeNode(9);
    root->left = new TreeNode(8);
    root->right = new TreeNode(12);
    root->left->left = new TreeNode(5);
    root->left->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(7);
    root->left->left->left->left = new TreeNode(2);
    root->left->left->left->right = new TreeNode(4);
    root->left->left->left->left->left = new TreeNode(1);
    root->left->left->right->left = new TreeNode(6);
    root->left->left->right->right = new TreeNode(8);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(13);
    root->right->left->right = new TreeNode(11);

    int val = 5;
    TreeNode* root1 = deleteNode(root, val);

    printPreorder(root1);

} 

