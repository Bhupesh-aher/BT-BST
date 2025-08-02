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

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while(!q.empty()){
        auto p = q.front();
        q.pop();
        TreeNode* node = p.first;
        int x = p.second.first, y = p.second.second;
        nodes[x][y].insert(node->val);
        if(node->left != NULL) q.push({node->left, {x - 1, y + 1}});
        if(node->right != NULL) q.push({node->right, {x + 1, y + 1}});
    }
    vector<vector<int>> ans;
    for(auto it: nodes){
        vector<int> res;
        for(auto q: it.second){
            res.insert(res.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(res);
    }
    return ans;
}

// TC - O(N * log2N * log2N * log2N) where N represents the number of nodes in the Binary Tree.
// Postorder Traversal performed using BFS as a time complexity of O(N) as we are visiting each and every node once.
// Multiset Operations to insert overlapping nodes at a specific vertical and horizontal level also takes O(log2N) complexity.
// Map operations involve insertion and retrieval of nodes with their vertical and level as their keys. Since there are two nested maps, the total time complexity becomes O(log2N)*O(log2N). 
// SC - O(N) 

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right->left= new TreeNode(9);
    root->right->right= new TreeNode(10);


    vector<vector<int>> ans = verticalTraversal(root);

    for(auto it: ans) {
        for(auto ele: it){
            cout << ele << " ";
        }
        cout << endl;
    }
} 

