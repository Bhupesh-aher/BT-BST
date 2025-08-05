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

void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track, TreeNode* target){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* current = q.front();
        q.pop();
        if(current->left != NULL){
            parent_track[current->left] = current;
            q.push(current->left); 
        } 
        if(current->right != NULL){
            parent_track[current->right] = current;
            q.push(current->right);
        }
    }
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent_track; // child -> parent
    markParent(root, parent_track, target);
    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> q;
    q.push(target);
    visited[target] = true;
    int dis = 0;
    while(!q.empty()){
        int size = q.size();
        if(dis == k) break;
        dis ++;
        for(int i = 0; i<size; i++){
            TreeNode* current = q.front();
            q.pop();
            if(current->left != NULL && !visited[current->left]){
                q.push(current->left);
                visited[current->left] = true;
            }
            if(current->right != NULL && !visited[current->right]){
                q.push(current->right);
                visited[current->right] = true;
            }
            if(parent_track[current] && !visited[parent_track[current]]){
                q.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }
    vector<int> result;
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        result.push_back(node->val);
    }
    return result; 
}
 

// TC - O(N) + O(N)
// SC - O(N) + O(2N) 


int main(){
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    
    int k = 2;
    vector<int> ans = distanceK(root, root->left, k);

    for(auto it: ans) cout << it << " "; 
    
} 

