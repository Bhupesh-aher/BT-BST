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

int maxSum(TreeNode* root, int &maxi) {
    if(root == NULL) return 0;

    int leftSum = max(0, maxSum(root->left, maxi));
    int rightSum = max(0, maxSum(root->right, maxi));

    maxi = max(maxi, leftSum + rightSum + root->val);
    return root->val + max(leftSum, rightSum);
}
int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;
    maxSum(root, maxi);
    return maxi;
}

// TC - O(N) 
// SC - O(N) 

int main(){
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Maximum Path Sum is " << maxPathSum(root);
} 

