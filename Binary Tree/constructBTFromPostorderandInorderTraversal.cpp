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
    
    travserseTree(root->left);
    travserseTree(root->right);
    cout << root->val << " ";
}

TreeNode* buildTreePostIn(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> &mpp){
    if(inStart > inEnd || postStart > postEnd) return NULL;

    TreeNode* root = new TreeNode(postorder[postEnd]);
    int inRoot = mpp[root->val];
    int numsLeft = inRoot - inStart;

    root->left = buildTreePostIn(postorder, postStart, postStart + numsLeft - 1, inorder, inStart, inRoot - 1, mpp);
    root->right = buildTreePostIn(postorder, postStart + numsLeft, postEnd - 1, inorder, inRoot + 1, inEnd, mpp);

    return root;

}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    map<int, int> mpp;
    for(int i = 0; i<inorder.size(); i++) mpp[inorder[i]] = i;

    TreeNode* root = buildTreePostIn(postorder, 0, postorder.size() - 1,  inorder, 0, inorder.size() - 1, mpp);
    return root;
}

// TC - O(N)
// SC - O(N) 


int main(){
    
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> postorder = {40, 50, 20, 60, 30, 10};
    TreeNode* root = buildTree(inorder, postorder);

    travserseTree(root);
    
} 

