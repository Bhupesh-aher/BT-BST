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



vector<vector<int>> prePostIn(Node* root){
    stack<pair<Node*, int>> st;
    st.push({root, 1});
    vector<int> pre, post, in;
    while(!st.empty()){
        auto it = st.top();
        st.pop();

        // this is part of pre 
        // increment 1 to 2
        if(it.second == 1){
            pre.push_back(it.first->data);
            it.second ++;
            st.push(it);

            if(it.first->left != NULL){
                st.push({it.first->left, 1});
            }
        }

        // this is part of in 
        // increment 2 to 3
        else if(it.second == 2){
            in.push_back({it.first->data});
            it.second ++;
            st.push(it);

            if(it.first->right != NULL){
                st.push({it.first->right, 1});
            }
        }

        // don't push it back again
        else {
            post.push_back({it.first->data});
        }
    }

    vector<vector<int>> ans;
    ans.push_back(pre);
    ans.push_back(in);
    ans.push_back(post);
    return ans;
}

// TC - O(3*N) 
// SC - O(4N) 


int main(){
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> pre, in, post;
    vector<vector<int>> ans = prePostIn(root);

    pre = ans[0];
    in = ans[1];
    post = ans[2];

    cout << "Preorder, postorder and inorder in one traversal - ";

    cout << endl;

    
    cout << "Preorder traversal - ";
    for(auto it: pre) cout << it << " ";

    cout << endl;

    cout << "Inorder traversal - ";
    for(auto it: in) cout << it << " ";

    cout << endl;

    cout << "Postorder traversal - ";
    for(auto it: post) cout << it << " ";
   
}
