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

// in markParent we use the same logic which we saw in previous problem (print all nodes at distance k) for marking parent node

int burnTree(TreeNode* target, unordered_map<TreeNode*, TreeNode*> &parent_track){
    queue<TreeNode*> q;
    q.push(target);
    int time = 0;
    map<TreeNode*, bool> visited;
    visited[target] = true;
    while(!q.empty()){
        int size = q.size();
        int fl = 0;
        for(int i = 0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();
            if(node->left && !visited[node->left]){
                fl = 1;
                q.push(node->left);
                visited[node->left] = true;
            }
            if(node->right && !visited[node->right]){
                fl = 1;
                q.push(node->right);
                visited[node->right] = true;
            }
            if(parent_track[node] && !visited[parent_track[node]]){
                fl = 1;
                q.push(parent_track[node]);
                visited[parent_track[node]] = true;
            }
        }
        if(fl == 1) time ++;
    }
    return time;
}
TreeNode* markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, int start){
    queue<TreeNode*> q;
    q.push(root);
    TreeNode* node;
    while(!q.empty()){
        TreeNode* current = q.front();
        q.pop();
        if(current->val == start) node = current;
        if(current->left != NULL) {
            parent_track[current->left] = current;
            q.push(current->left);
        }
        if(current->right != NULL) {
            parent_track[current->right] = current;
            q.push(current->right);
        }
    }
    return node;
}
int amountOfTime(TreeNode* root, int start) {
    unordered_map<TreeNode*, TreeNode*> parent_track;
    TreeNode* target = markParent(root, parent_track, start);
    int maxi = burnTree(target, parent_track);
    return maxi;
}

// TC - O(N) + O(N)
// SC - O(N) + O(2N) 


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(7);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);
    
    int start = 2;
    cout << amountOfTime(root, start);
    
} 

