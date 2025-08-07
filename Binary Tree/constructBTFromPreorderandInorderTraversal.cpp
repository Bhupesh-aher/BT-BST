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

TreeNode* builtTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int>& inOrderMap);

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
map<int, int> inOrderMap;
for(int i = 0; i<inorder.size(); i++) inOrderMap[inorder[i]] = i;

TreeNode* root = builtTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size() - 1, inOrderMap);
return root;
}

TreeNode* builtTree(vector<int>&preorder, int preStart, int preEnd, vector<int>&inorder, int inStart, int inEnd,  map<int, int> &inOrderMap){
    if(preStart > preEnd || preStart > preEnd) return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);
    int inRoot = inOrderMap[root->val];
    int numsLeft = inRoot - inStart;

    root->left = builtTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inOrderMap);
    root->right = builtTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inOrderMap);

    return root;
}

// TC - O(N)
// SC - O(N) 


int main(){
    
    vector<int> inorder = {40, 20, 50, 10, 60, 30};
    vector<int> preorder = {10, 20, 40, 50, 30, 60};
    TreeNode* root = buildTree(preorder, inorder);

    travserseTree(root);
    
} 

