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

void printInorder(TreeNode* root){
    if(root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}


 void inorderTraversal(TreeNode* root, vector<int> &inorder){
    if(root == NULL) return;
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right, inorder);
}
void changeBST(TreeNode* root, int &i, vector<int> &inorder){
    if(root == NULL) return;
    changeBST(root->left, i, inorder);
    root->val = inorder[i++];
    changeBST(root->right, i, inorder);
}
void recoverTree(TreeNode* root) {
    vector<int> inorder;
    inorderTraversal(root, inorder);
    sort(inorder.begin(), inorder.end());
    int i = 0;
    changeBST(root, i, inorder);
}


// TC - O(2N) + O(N log N) 
// SC - O(N) + O(N)





class Solution {
private: 
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
public:
    void inorder(TreeNode* root){
        if(root == NULL) return;
        inorder(root->left);

        // if this is first violation, mark these two nodes as
        // first and middle
        if(prev != NULL && (root->val < prev->val)){

            if(first == NULL){
                first = prev;
                middle = root;
            }
            // if this is second violation, mark this this node as last
            else {
                last = root;
            }
        }

        // mark this node as prev
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
    }
};

// TC - O(N)
// SC - O(N)


int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    cout << "Inorder of incorrect BST  - ";
    printInorder(root);
    cout << endl;

    recoverTree(root);
    cout << "Inorder of BST after recovery  - ";
    printInorder(root);

} 



