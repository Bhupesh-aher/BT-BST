#include<bits/stdc++.h>
using namespace std;

// Given BST which is also complete Complete Binary Tree (CBT) convert it into a Min Heap
// With the condition that all the values in the left subtree of a node should be less than all the values in the right subtree of the node. This condition is applied to all the nodes 

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

void printMinHeap(TreeNode* root){
    if(root == NULL) return;
    cout << root->val << " ";
    printMinHeap(root->left);
    printMinHeap(root->right);
}


void inorder(TreeNode* root, vector<int> &in){
    if(root == NULL) return;
    inorder(root->left, in);
    in.push_back(root->val);
    inorder(root->right, in);
}

void preorder(TreeNode* root, int &index, vector<int> &in){
    if(root == NULL) return;
    root->val = in[index++];
    preorder(root->left, index, in);
    preorder(root->right, index, in);
}

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    vector<int> in;
    inorder(root, in);
    int index = 0;
    preorder(root, index, in);

    cout << "Printing the min heap after converting the BST to Min Heap" << endl;
    printMinHeap(root);



} 




