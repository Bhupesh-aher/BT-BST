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

// InOrder - (left root right)

void inOrder(Node* root){
    if(root == NULL) 
        return;
    
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}



int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    inOrder(root);
}