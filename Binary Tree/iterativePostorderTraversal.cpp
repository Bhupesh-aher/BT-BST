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

// Iterative Postorder Traversal using 2 Stack
// Postorder - (left right root)

vector<int> iterativePostOrder(Node* root){
    vector<int> postOrder;
    stack<Node*> st1;
    stack<Node*> st2;
    st1.push(root);
    while(!st1.empty()){
        Node* node = st1.top();
        st1.pop();
        st2.push(node);
        if(node->left != NULL) st1.push(node->left);
        if(node->right != NULL) st1.push(node->right);
    }
    while(!st2.empty()){
        postOrder.push_back(st2.top()->data);
        st2.pop();
    }
    return postOrder;
}

// TC - O(N) 
// SC - O(2N) 


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

    vector<int> postOrder = iterativePostOrder(root);

    cout << "Iterative Postorder Traversal using 2 Stack - " << endl;
    for(auto it: postOrder) cout << it << " ";
   
} 