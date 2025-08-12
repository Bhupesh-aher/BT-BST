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
    pre.push_back(root->val);
    traverse(root->left, pre);
    traverse(root->right, pre);
}
int kthSmallest(TreeNode* root, int k) {
    vector<int> pre;
    traverse(root, pre);
    sort(pre.begin(), pre.end());
    return pre[k-1];
}

// TC - O(N) + O(N log N)
// SC - O(N) + O(N)



void inorder(TreeNode* root, int& counter, int k, int& smallest){
    if(root == NULL || counter >= k) return;

    inorder(root->left, counter, k, smallest);
    counter ++;
    if(counter == k){
        smallest = root->val;
        return;
    }
    inorder(root->right, counter, k, smallest);

}
int kthSmallest(TreeNode* root, int k) {
    int smallest = -1;
    int counter = 0;
    inorder(root, counter, k, smallest);
    return smallest;
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
    cout << "Kth Smallest Element is " << kthSmallest(root, k);

} 

