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

// val <= key 
int floorInBST(TreeNode* root, int key){
    int floor = -1;
    while(root != NULL){
        if(root == NULL) return floor;
        if(root->val == key){
            floor = root->val;
            return floor;
        }
        if(key < root->val){
            root = root->left;
        }
        else {
            floor = root->val;
            root = root->right;
        }
    }
    return floor;
}


// TC - O(log2N)  log2N is the height of the tree
// SC - O(h) where 'h' represents the height of the tree



int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(17);
    root->left->right->left = new TreeNode(6);

    int key = 9;
    cout << floorInBST(root, key);
    
} 

