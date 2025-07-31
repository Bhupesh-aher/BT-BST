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

bool isLeaf(TreeNode* root) {
    if(root->left == NULL && root->right == NULL) return true;
    return false; 
}


void addLeftBoundary(TreeNode* root, vector<int> &ans){
    TreeNode* curr = root->left;
    while(curr){
        if(!isLeaf(curr)) ans.push_back(curr->val);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}
// O(H)

void addRightBoundary(TreeNode* root, vector<int> &ans){
    TreeNode* curr = root->right;
    vector<int> res;
    while(curr){
        if(!isLeaf(curr)) res.push_back(curr->val);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    for(int i = res.size() - 1; i>=0; i--){
        ans.push_back(res[i]);
    }
}
// O(H) 

void addLeaves(TreeNode* root, vector<int>  &ans){
    if(isLeaf(root)) {
        ans.push_back(root->val);
        return;
    }
    if(root->left) addLeaves(root->left, ans);
    if(root->right) addLeaves(root->right, ans);
}
// O(N) 

vector<int> boundaryTraversal(TreeNode* root){
    vector<int> ans;
    if(!root) return ans;
    if(!isLeaf(root)) ans.push_back(root->val);
    addLeftBoundary(root, ans);
    addLeaves(root, ans);
    addRightBoundary(root, ans);
    return ans;
}

// TC - O(H) + O(H) + O(N) = O(N) 
// SC - O(N) 

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(4);
    root->left->left->right->left = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    root->right->right->left->left = new TreeNode(10);
    root->right->right->left->right = new TreeNode(11);


    vector<int> ans = boundaryTraversal(root);

    for(auto it: ans) cout << it << " "; 
} 

