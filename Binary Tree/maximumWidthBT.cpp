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

int widthOfBinaryTree(TreeNode* root) {
    if(!root) return 0;
    int ans = 0;
    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});
    while(!q.empty()){
        int size = q.size();
        unsigned long long mini = q.front().second;
        unsigned long long first, last;
        for(int i = 0; i<size; i++){
            unsigned long long curr_id = q.front().second - mini;
            TreeNode* node = q.front().first;
            q.pop();
            if(i == 0) first = curr_id;
            if(i == size - 1) last = curr_id;
            if(node->left){
                q.push({node->left,  2 * curr_id + 1});
            } 
            if(node->right) {
                q.push({node->right, 2 * curr_id + 2});
            }
        }
        ans = max(ans, static_cast<int>(last - first + 1));
    }
    return ans;
}

// TC - O(N)
// SC - O(N) 


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->left->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(7);
    
    cout << widthOfBinaryTree(root);
    
} 

