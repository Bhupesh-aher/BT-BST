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

int maxi = INT_MIN;
int findHeightOfTree(TreeNode* root){
    if(root == NULL) return 0;
    int left = findHeightOfTree(root->left);
    int right = findHeightOfTree(root->right);
    return 1 + max(left, right);
}

void diameter(TreeNode* root){
    if(root == NULL) return;

    int leftHeight = findHeightOfTree(root->left);
    int rightHeight = findHeightOfTree(root->right);
    maxi = max(maxi, leftHeight + rightHeight);
    
    diameter(root->left);
    diameter(root->right);
}
int diameterOfBinaryTree(TreeNode* root) {
    diameter(root);
    return maxi;
}

// TC - O(N * N) = O(N^2)
// SC - O(N) 



int height(TreeNode* root, int &maxi){
    if(root == NULL) return 0;
    int leftHeight = height(root->left, maxi);
    int rightHeight = height(root->right, maxi);
    maxi = max(maxi, leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}
int diameterOfBinaryTree(TreeNode* root) {
    int maxi = 0;
    height(root, maxi);
    return maxi;
}

// TC - O(N) 
// SC - O(N) 

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Diameter of the BT is " << diameterOfBinaryTree(root);
} 

