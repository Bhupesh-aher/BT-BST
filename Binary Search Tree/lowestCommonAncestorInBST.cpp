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
    if(root == NULL) return NULL;
    int curr = root->val;
    if(curr < p->val && curr < q->val){
    return lowestCommonAncestor(root->right, p, q);
    }
    if(curr > p->val && curr > q->val) {
    return lowestCommonAncestor(root->left, p, q);
    }
    return root;
}

// TC - O(log2N)  log2N is the height of the tree
// SC - O(h) where 'h' represents the height of the tree

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(4);
    root->right = new TreeNode(13);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(8);
    root->left->left->left = new TreeNode(1);
    root->left->left->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(9);
    root->left->right->left->left = new TreeNode(5);
    root->left->right->left->right = new TreeNode(7);
    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(15);


    // lca(5, 9) 
    TreeNode* lca = lowestCommonAncestor(root, root->left->right->left->left, root->left->right->right);
    cout << lca->val;
   

} 

