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

int tr(TreeNode* root){
    if(root == NULL) return 0;

    int left = tr(root->left);
    int right = tr(root->right);
    return 1 + max(left, right);
}

bool check(TreeNode* root){
    if(root == NULL) return true;

    int leftHeight = tr(root->left);
    int rightheight = tr(root->right);

    if(abs(leftHeight- rightheight) > 1) return false;
    int left = check(root->left);
    int right = check(root->right);

    if(!left || !right) return false;
    return true;
    
}
bool isBalanced(TreeNode* root) {
    return check(root);
}

// TC - O(N * N) = O(N^2)
// SC - O(N) 



int tr(TreeNode* root){
    if(root == NULL) return 0;

    int leftHeight = tr(root->left);
    if(leftHeight == -1) return -1;
    
    int rightHeight = tr(root->right);
    if(rightHeight == -1) return -1;

    if(abs(leftHeight - rightHeight) > 1) return -1;
    return 1 + max(leftHeight, rightHeight);
}


bool isBalanced(TreeNode* root) {
    if(tr(root) == -1) return false;
    return true;
}


// we use the same code of to find the height of BT. and we just add 2 conditions and that will helps us to check the balanced BT
// so we will return -1 if subtree is not balanced BT 
// and if the tree is balanced BT than return the height of the tree

// TC - O(N)  
// SC - O(N) 


int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    if(isBalanced(root) == 1) cout << "Balanced Tree";
    else cout << "Not balanced Tree";
} 

