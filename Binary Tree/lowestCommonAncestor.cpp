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


// we use the exact approach to find the path which we used in previous problem (print root to node path)
// we find path for both p and q individually and than compare there path and find the lca node

bool getPath(TreeNode* root, vector<int> &path, TreeNode* x){
    if(root == NULL) return false;
    path.push_back(root->val);
    if(root->val == x->val) return true;

    if(getPath(root->left, path, x) || getPath(root->right, path, x)) {
        return true;
    }
    path.pop_back();
    return false;
    
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<int> path1, path2;
    getPath(root, path1, p);
    getPath(root, path2, q);

    int i = 0, node = -1;
    while (i < path1.size() && i < path2.size()) {
        if (path1[i] == path2[i]) {
            node = path1[i];
            i++;
        } else {
            break;
        }
    }
    return new TreeNode(node); 
}

// TC - 2 * O(N)
// SC - 2 * O(N) 



TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL || root == p || root == q) return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if(left == NULL) return right;
    else if(right == NULL) return left;
    else { // both left and right are not null, we found our result
        return root;
    }
}

// TC - O(N)
// SC - O(N) 


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);

    
    TreeNode* Node = lowestCommonAncestor(root, root->left->left, root->left->right->left);
    cout << Node->val;
    
} 

