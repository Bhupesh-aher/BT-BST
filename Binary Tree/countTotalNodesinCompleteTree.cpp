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

int f(TreeNode* root, int &cnt){
    if(root == NULL) return 0;
    cnt ++;
    f(root->left, cnt);
    f(root->right, cnt);
    return cnt;
}
int countNodes(TreeNode* root) {
    int cnt = 0;
    f(root, cnt);
    return cnt;

}

// TC - O(N)
// SC - O(h)




int findLeftHeight(TreeNode* node){
    int height = 0;
    while(node != NULL){
        height ++;
        node = node->left;
    }
    return height;
}

int findRightHeight(TreeNode* node){
    int height = 0;
    while(node != NULL){
        height ++;
        node = node->right;
    }
    return height;
}
int countNodes(TreeNode* root) {
    if(root == NULL) return 0;
    int lh = findLeftHeight(root);
    int rh = findRightHeight(root);

    if(lh == rh) return (1<<lh) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// TC - O(log n)^2
// SC - O(log n)


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    
    cout << countNodes(root);
    
} 

