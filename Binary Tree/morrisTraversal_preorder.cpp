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

vector<int> preorder(TreeNode* root){
    vector<int> preOrder;
    TreeNode* curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            preOrder.push_back(curr->val);
            curr = curr->right;
        }
        else {
            TreeNode* prev = curr->left;
            while(prev->right != NULL && prev->right != curr){
                prev = prev->right;
            }

            if(prev->right == NULL){
                prev->right = curr;
                preOrder.push_back(curr->val);
                curr = curr->left;
            }
            else {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return preOrder;
}


// TC - O(N)
// SC - O(1) 


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    
    vector<int> ans = preorder(root);

    for(auto it: ans) cout << it << " "; 
    
} 

