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

// PreOrder - (root left right)

vector<int> iterativePreOrder(Node* root){
    vector<int> preOrder;
    if(root == NULL) return preOrder;
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* node = st.top();
        st.pop();
        preOrder.push_back(node->data);
        if(node->right != NULL) st.push(node->right);
        if(node->left != NULL) st.push(node->left);
    }
    return preOrder;
}

// TC - O(N) SC - O(N) 

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

    vector<int> preOrder = iterativePreOrder(root);

    cout << "Iterative Preorder Traversal - " << endl;
    for(auto it: preOrder) cout << it << " ";
   
} 