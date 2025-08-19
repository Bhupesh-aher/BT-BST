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


bool isValidBST(TreeNode* root, int minVal, int maxVal) {
    if (root == nullptr) return true;
    if (root->val >= maxVal || root->val <= minVal) return false;
    return isValidBST(root->left, minVal, root->val) &&
            isValidBST(root->right, root->val, maxVal);
}

int countNodes(TreeNode* root){
    if(root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int largestBSTSubtree(TreeNode* root){
    if(root == NULL) return 0;
    if(isValidBST(root, INT_MIN, INT_MAX)){
        return countNodes(root);
    }
    else {
        int left = largestBSTSubtree(root->left);
        int right = largestBSTSubtree(root->right);
        return max(left, right);
    }
}


// TC - O(N) * O(N) = O(N^2)
// SC - O(N)




class NodeValue {
public: 
    int maxNode, minNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize){
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

NodeValue largestBSTSubtreeHelper(TreeNode* root){
    // An empty tree is a BST of size 0
    if(!root) return NodeValue(INT_MAX, INT_MIN, 0);

    // Get values from left and right subtree of current tree
    auto left = largestBSTSubtreeHelper(root->left);
    auto right = largestBSTSubtreeHelper(root->right);

    // current node is greater than max in left and smaller than min in right. it is a BST
    if(left.maxNode < root->val && root->val < right.minNode){
        // it is a BST
        return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), 
                left.maxSize + right.maxSize + 1);
    }

    // otherwise, return [-inf, inf] so that parent can't be valid BST
    return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
}

int largestBSTSubtree(TreeNode* root){
    return largestBSTSubtreeHelper(root).maxSize;
}

// TC - O(N)
// SC - O(N)





// babbar code
class info {
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info largestBSTHelper(TreeNode* root, int &ans){
    if(root == NULL) return {INT_MIN, INT_MAX, true, 0};

    info left = largestBSTHelper(root->left, ans);
    info right = largestBSTHelper(root->right, ans);

    info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->val, right.maxi);
    currNode.mini = min(root->val, left.mini);

    if(left.isBST && right.isBST && (left.maxi < root->val && root->val < right.mini)){
        currNode.isBST = true;
    }
    else currNode.isBST = false;

    if(currNode.isBST) {
        ans = max(ans, currNode.size);
    }
    return currNode;
}

int largestBST(TreeNode* root){
    int maxSize = 0;
    largestBSTHelper(root, maxSize);
    return maxSize;

}

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);

    int largestBSTSize = largestBSTSubtree(root);
    cout << "Size of the largest BST subtree: " << largestBSTSize;
} 





// TreeNode* root = new TreeNode(20);
// root->left = new TreeNode(15);
// root->right = new TreeNode(40);
// root->left->left = new TreeNode(14);
// root->left->right = new TreeNode(18);
// root->right->left = new TreeNode(30);
// root->right->right = new TreeNode(60);
// root->left->left->right = new TreeNode(17);
// root->left->right->left = new TreeNode(16);
// root->left->right->right = new TreeNode(19);
// root->right->right->left = new TreeNode(50);


