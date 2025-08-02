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

vector<int> bottomview(TreeNode* root) {
    vector<int> ans;
    if(root == NULL) return ans;
    queue<pair<TreeNode*, int>> q;
    map<int, int> mpp;
    q.push({root, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        TreeNode* node = it.first;
        int line = it.second;
        mpp[line] = node->val;

        if(node->left != NULL) q.push({node->left, line -1});
        if(node->right != NULL) q.push({node->right, line + 1});
    }

    for(auto it: mpp) ans.push_back(it.second);

    return ans;
}

// TC - O(N) where N is the number of nodes in the Binary Tree. This complexity arises from visiting each node exactly once during the BFS traversal.
// SC - O(N/2 + N/2) where N represents the number of nodes in the Binary Tree. 

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(8);
    root->left->right->right = new TreeNode(9);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    vector<int> ans = bottomview(root);

    for(auto it: ans) cout << it << " "; 
} 

