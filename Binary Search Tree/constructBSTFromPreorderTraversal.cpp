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

void printPreorder(TreeNode* root){
    if(root == NULL) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    if(preorder.empty()) return NULL;
    TreeNode* root = new TreeNode(preorder[0]);

    for(int i = 1; i<preorder.size(); i++){
        TreeNode* curr = root;
        while(true){
            if(preorder[i] < curr->val){
                if(curr->left == NULL){
                    curr->left = new TreeNode(preorder[i]);
                    break;
                }
                else curr = curr->left;
            }
            else {
                if(curr->right == NULL){
                    curr->right = new TreeNode(preorder[i]);
                    break;
                }
                else curr = curr->right;
            }
        }
    }
    return root;
}

// TC - O(N * N)
// SC - O(N) 




// The property of BST is when we do inorder of BST it comes out ot be sorted
// so what we can do is will store all ele from preorder in inorder arr and sort that inorder arr
// now if you remember we have solved one problem of constructing a BT from inorder and preorder
// we use the exact same code and logic and it will form a BST (a unique BST)


TreeNode* builtTree(vector<int>&preorder, int preStart, int preEnd, vector<int>&inorder, int inStart, int inEnd,  map<int, int> &inOrderMap){
    if(preStart > preEnd || inStart > inEnd) return NULL;

    TreeNode* root = new TreeNode(preorder[preStart]);
    int inRoot = inOrderMap[root->val];
    int numsLeft = inRoot - inStart;

    root->left = builtTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inOrderMap);
    root->right = builtTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inOrderMap);

    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    if(preorder.empty()) return NULL;
    int n = preorder.size();
    vector<int> inorder(n, -1);
    for(int i = 0; i<preorder.size(); i++) inorder[i] = preorder[i];
    sort(inorder.begin(), inorder.end());
    map<int, int> inOrderMap;
    for(int i = 0; i<inorder.size(); i++) inOrderMap[inorder[i]] = i;

    TreeNode* root = builtTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inOrderMap);

    return root;
}

// TC - O(N) + O(N log N)
// SC - O(N) + O(N)



// we use the range concept here just like we did in check if tree is BST o not
// here instaed of taking both upper and lower range we just take the upper value(range)

TreeNode* built(vector<int>& preorder, int &i, int bound){
    if(i == preorder.size() || preorder[i] > bound) return NULL;
    TreeNode* root = new TreeNode(preorder[i++]);
    root->left = built(preorder, i, root->val);
    root->right = built(preorder, i, bound);
    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    int i = 0;
    return built(preorder, i, INT_MAX);
}

// TC - O(3N) = O(N)
// SC - O(N)



int main(){
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    TreeNode* root = bstFromPreorder(preorder);

    printPreorder(root);
} 

