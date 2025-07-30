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

// Iterative Postorder Traversal using 1 Stack
// Postorder - (left right root)

vector<int> iterativePostOrder(Node* root){
    vector<int> postOrder;
    if(root == NULL) return postOrder;
    stack<Node*> st;
    Node* curr = root;

    while(curr != NULL || !st.empty()){
        if(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        else {
            Node* temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                postOrder.push_back(temp->data);
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    postOrder.push_back(temp->data);
                }
            }
            else {
                curr = temp;
            }
        }
    }
    return postOrder;
}

// TC - O(2N) 
// SC - O(N) 


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

    cout << "Iterative Postorder Traversal using 1 Stack - " << endl;
    for(auto it: postOrder) cout << it << " ";
   
} 