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


void printPreorder(TreeNode* root){
    if(root == NULL) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

void printFlattenTree(TreeNode* root){
    if(root == NULL) return;
    cout << root->val << " ";
    printFlattenTree(root->right);
}


class Solution {
    public:
    TreeNode* prev = NULL;
    void flattenToLL(TreeNode* root){
        if(!root) return;
        
        flattenToLL(root->right);
        flattenToLL(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

void flatten(TreeNode* root) {
   Solution sol;
   sol.flattenToLL(root);
}


// TC - O(N)
// SC - O(N) 



void flatten(TreeNode* root) {
    if(root == NULL) return;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* curr = st.top();
        st.pop();
        if(curr->right != NULL) st.push(curr->right);
        if(curr->left != NULL) st.push(curr->left);
        
        if(!st.empty()){
            curr->right = st.top();
        }
        curr->left = NULL;
    }
}

// TC - O(N)
// SC - O(N) 



// used morris traversal
void flatten(TreeNode* root) {
    if(root == NULL) return;
    TreeNode* curr = root;
    while(curr != NULL){
        if(curr->left != NULL){
            TreeNode* prev = curr->left;
            while(prev->right != NULL){
                prev = prev->right;
            }
            prev->right = curr->right;
            curr->right = curr->left;

            curr->left = NULL;
        }
        curr = curr->right;
    }
}


// TC - O(N)
// SC - O(1) 



int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    root->right->right->left = new TreeNode(7);

    cout << "Binary Tree Preorder: ";
    printPreorder(root);
    cout << endl;

    flatten(root);
    
    cout << "Binary Tree After Flatten: ";
    printFlattenTree(root);
    
    
} 

