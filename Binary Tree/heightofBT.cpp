#include<bits/stdc++.h>
using namespace std;

struct Node {
    public: 
    int data;
    Node* left;
    Node* right;

    public:
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};


// i wrote this code
int tr(Node* root){
    if(root == NULL) return 0;

    int left = 1 + tr(root->left);
    int right = 1 + tr(root->right);
    return max(left, right);
}
int maxDepth(Node* root) {
    return tr(root);
}


// strivers code
int tr(Node* root){
    if(root == NULL) return 0;

    int left = tr(root->left);
    int right = tr(root->right);
    return 1 + max(left, right);
}
int maxDepth(Node* root) {
    return tr(root);
}

// TC - O(N) 
// SC - O(N) 


// Here we have used the recursion way but you can also use BFS (level order traversal) to find the height of tree
// Both code logic is exact same. just i wrote it in more beginner way and striver wrote it more short way



int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->left = new Node(5);
    root->right->right = new Node(6);

    cout << "Height of the tree is  " << maxDepth(root);
} 