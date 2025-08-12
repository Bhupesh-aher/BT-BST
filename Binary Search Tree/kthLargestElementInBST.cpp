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

void traverse(TreeNode* root, vector<int> &pre){
    if(root == NULL) return;
    traverse(root->left, pre);
    pre.push_back(root->val);
    traverse(root->right, pre);
}
int kthLargest(TreeNode* root, int k) {
    vector<int> pre;
    traverse(root, pre);
    return pre[pre.size() - k];
}

// TC - O(N)
// SC - O(N) + O(N)



void inorder(TreeNode* root, int& counter, int k, int& largest){
    if(root == NULL || counter >= k) return;

    inorder(root->right, counter, k, largest);
    counter ++;
    if(counter == k){
        largest = root->val;
        return;
    }
    inorder(root->left, counter, k, largest);

}
int kthLargest(TreeNode* root, int k) {
    int largest = -1;
    int counter = 0;
    inorder(root, counter, k, largest);
    return largest;
}

// TC - O(N)
// SC - O(N) 


int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(8);

    int k = 3;
    cout << "Kth Largest Element is " << kthLargest(root, k);

} 

