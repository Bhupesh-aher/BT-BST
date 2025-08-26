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

// is given binary tree a max-heap or not
// CBT - complete binary tree

int countNo_ofNodes(TreeNode* root){
    if(root == NULL) return 0;

    int left = countNo_ofNodes(root->left);
    int right = countNo_ofNodes(root->right);
    return 1 + left + right;
}

bool isCBT(TreeNode* root, int index, int totalCount){
    if(root == NULL) return true;

    if(index > totalCount) return false;
    else {
        int left = isCBT(root->left, 2 * index + 1, totalCount);
        int right = isCBT(root->right, 2 * index + 2, totalCount);
        return left && right;
    }
}

bool isMaxOrder(TreeNode* root){
    // leaf node
    if(root->left == NULL && root->right == NULL) return true;

    // right is null means just comparing root with left of root
    if(right == NULL) {
        return (root->val > root->left->val);
    }
    else {      // both left and right of root is there
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right && (root->val > root->left->val && root->val > root->right->val));
    }
}

bool isHeap(TreeNode* root){
    int totalCount = countNo_ofNodes(root);
    int index = 0;
    return isCBT(root, 0, totalCount) && isMaxOrder(root);

}

int main(){

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    bool isBtHeap = isHeap(root);
    if(isBtHeap == 1) cout << "This Binary Tree is a Heap";
    else cout << "This Binary Tree is not a heap";
    
} 




