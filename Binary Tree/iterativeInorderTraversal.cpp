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

vector<int> iterativeInOrder(Node* root){
    vector<int> inOrder;
    stack<Node*> st;
    Node* node = root;

    while(true){
        if(node != NULL){
            st.push(node);
            node = node->left;
        }
        else {
            if(st.empty()) break;
            node = st.top();
            st.pop();
            inOrder.push_back(node->data);
            node = node->right;
        }
    }
    return inOrder;
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

    vector<int> inOrder = iterativeInOrder(root);

    cout << "Iterative Inorder Traversal - " << endl;
    for(auto it: inOrder) cout << it << " ";
   
} 