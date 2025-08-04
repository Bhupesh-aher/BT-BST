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



bool getPath(TreeNode* root, vector<int> &ans, int x){
    if(root == NULL) return false;

    ans.push_back(root->val);
    if(root->val == x) return true;

    if(getPath(root->left, ans, x) || getPath(root->right, ans, x)) {
        return true;
    }

    ans.pop_back();
    return false;
    
}

// TC - O(N)
// SC - O(N)  

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    
    
    vector<int> ans;
    int x = 7;
    getPath(root, ans, x);
    
    for(auto it: ans) cout << it << " "; 

    
} 

