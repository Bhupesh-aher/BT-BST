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

void travserseTree(TreeNode* root){
    if(root == NULL) 
        return;
    
    cout << root->val << " ";
    travserseTree(root->left);
    travserseTree(root->right);
}


// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    if(root == NULL) return "";
    string s = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* currNode = q.front();
        q.pop();
        if(currNode == NULL) s.append("#,");
        else s.append(to_string(currNode->val)+',');
        if(currNode != NULL){
            q.push(currNode->left);
            q.push(currNode->right);
        }
    }
    return s;

}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if(data.size() == 0) return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();

        getline(s, str, ',');
        if(str == "#"){
            node->left = NULL;
        }
        else {
            TreeNode* leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(s, str, ',');
        if(str == "#"){
            node->right = NULL;
        }
        else {
            TreeNode* rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

// TC - O(N)
// SC - O(N) 


int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    
    string data = serialize(root);
    cout << data << endl;

    TreeNode* node = deserialize(data);

    travserseTree(node);
} 

