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


bool isValid(TreeNode* root, long long minVal, long long maxVal){
    if(root == NULL) return true;
    if(root->val >= maxVal || root->val <= minVal) return false;
    return isValid(root->left, minVal, root->val) && isValid(root->right, root->val, maxVal);

}
bool isValidBST(TreeNode* root) {
    return isValid(root, LLONG_MIN, LLONG_MAX);
}


// TC - O(N)
// SC - O(N) 


int main(){
    TreeNode* root = new TreeNode(13);
    root->left = new TreeNode(10);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(12);
    root->left->left->right = new TreeNode(9);
    root->left->left->right->left = new TreeNode(8);
    root->right->left = new TreeNode(14);
    root->right->right = new TreeNode(17);
    root->right->right->left = new TreeNode(16);

    
    if(isValidBST(root)) cout << "Tree is BST ";
    else cout << "Tree is not BST";

} 

