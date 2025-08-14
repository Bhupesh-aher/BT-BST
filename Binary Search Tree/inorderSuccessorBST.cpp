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

int binarySearch(vector<int> &inorder, int target){
    int left = 0;
    int right = inorder.size() - 1;
    
    while(left <= right){
        int mid = left + (right - left) / 2;

        if(inorder[mid] == target){
            return mid;
        }
        else if(inorder[mid] < target){
            left = mid + 1;
        }
        else right = mid - 1;
    }

    // If target not found,
    // return the index for insertion
    return left == inorder.size() ? -1 : left;
}

void inorderTraversal(TreeNode* root, vector<int> &inorder){
    if(root == NULL) return;
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right, inorder);
}

TreeNode* inoderSuccessor(TreeNode* root, TreeNode* p){
    vector<int> inorder;

    // Perform in-order traversal to
    // generate the sorted list
    inorderTraversal(root, inorder);

    // Binary search to find the
    // index of the node's value
    int index = binarySearch(inorder, p->val);

    // If index is out of range or it's the
    // last element, return nullptr
    if(index == inorder.size() -1 ||  index == -1) return NULL;

    // Return the next element
    // as the inorder successor
    return new TreeNode(inorder[index + 1]);
}

// TC - O(N) + O(log N)
// SC - O(N) + O(N)




TreeNode* inoderSuccessor(TreeNode* root, TreeNode* p){
    TreeNode* successor = NULL;
    while(root != NULL){
        if(root->val > p->val){
            successor = root;
            root = root->left;
        }
        else root = root->right;
    }
    return successor;
}

// TC - O(N)
// SC - O(N)


TreeNode* inoderSuccessor(TreeNode* root, TreeNode* p){
    TreeNode* successor = NULL;
    while(root != NULL){
        if(p->val >= root->val){
            root = root->right;
        }
        else {
            successor = root;
            root = root->left;
        }
    }
    return successor;
}

// TC - O(h)
// SC - O(N)

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root->right->right->left = new TreeNode(8);
    root->right->right->right = new TreeNode(10);

    cout << "Inorder of BST - ";
    printInorder(root);
    cout << endl;

    TreeNode* p = root->right->right->left;
    TreeNode* successor = inoderSuccessor(root, p);

    // Print the inorder successor's value
    if (successor != nullptr) cout << "Inorder Successor of " << p->val << " is: " << successor->val << endl;
    else cout << "Inorder Successor of " << p->val << " does not exist." << endl;
    
} 