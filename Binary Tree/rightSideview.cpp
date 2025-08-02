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

// level order traversal 
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i<size; i++){
            TreeNode* node = q.front();
            if(i == size - 1) ans.push_back(node->val);
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
        }
    }
    return ans;
}

// TC - O(N)
// SC - O(N)




// recursive 
void rightSide(TreeNode* root, int level, vector<int> &ans){
    if(root == NULL) return;

    if(level == ans.size()) ans.push_back(root->val);
    rightSide(root->right, level + 1, ans);
    rightSide(root->left, level + 1, ans);
}
vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    rightSide(root, 0, ans);
    return ans;
}

// TC - O(N) where N is the number of nodes in the Binary Tree. This complexity arises as we travel along the height of the Binary Tree. For a balanced binary tree, the height is log2N but in the worst case when the tree is skewed, the complexity becomes O(N).
// SC - O(H) where N is the number of nodes in the Binary Tree. This complexity arises because we store the leftmost and rightmost nodes in an additional vector. The size of this result vector is proportional to the height of the Binary Tree which will be log2N when the tree is balanced and O(N) in the worst case of a skewed tree.

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    vector<int> ans = rightSideView(root);

    for(auto it: ans) cout << it << " "; 
} 

