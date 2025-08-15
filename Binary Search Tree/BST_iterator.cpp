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

void printInorder(TreeNode* root){
    if(root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

class BSTIterator {
private: 
    vector<int> inorder;
    int pointer;

    void inorderTraversal(TreeNode* root){
        if(root == NULL) return;
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
    }
public:
    BSTIterator(TreeNode* root) {
        pointer = -1;
        inorderTraversal(root);
    }
    
    int next() {
        pointer ++;
        return inorder[pointer];
    }
    
    bool hasNext() {
        return pointer + 1 < inorder.size();
    }
};



// TC - O(N) the overall time complexity of this approach is O(N) for constructing the iterator and O(1) for each subsequent operation of hasNext() and next()
// SC - O(N)




class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        // Get the top node from stack
        TreeNode* temp = st.top();
        // Remove the top node from stack
        st.pop();
        // Add leftmost nodes of the right subtree
        pushAll(temp->right);
        // Return the value of the removed node
        return temp->val;
    }
    
    bool hasNext() {
        // Returns true if stack is not empty
        return !st.empty();
    }
    private: 
        // Pushes all the leftmost nodes starting
        // from the given node onto the stack
        void pushAll(TreeNode* node){
            // Iterate through left nodes,
            // pushing each onto the stack
            for(; node != NULL; st.push(node), node = node->left);
        }
};


// TC - O(N) O(1)as next() and hasNext() occur is constant time, the element pushed onto the stack during traversal to the leftmost node and during subsequent traversals will take O(H) time for each traversal
// SC - O(h) where H is the height of the tree as the additional space required to store the nodes will be the height of the tree at maximum






int main(){
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    cout << "Inorder of BST - ";
    printInorder(root);
    cout << endl;

    // Create a BSTIterator object
    // initialized with the root of the BST
    BSTIterator bstIterator(root);

    // Function calls and their outputs
    cout << "Functions Called:" << endl;
    cout << "BSTIterator()" << endl;
    cout << "next(): " << bstIterator.next() << endl;
    cout << "next(): " << bstIterator.next() << endl;
    cout << "hasNext(): " << (bstIterator.hasNext() ? "true" : "false") << endl;
    cout << "next(): " << bstIterator.next() << endl;
    cout << "hasNext(): " << (bstIterator.hasNext() ? "true" : "false") << endl;
    cout << "next(): " << bstIterator.next() << endl;
    cout << "hasNext(): " << (bstIterator.hasNext() ? "true" : "false") << endl;
    cout << "next(): " << bstIterator.next() << endl;
    cout << "hasNext(): " << (bstIterator.hasNext() ? "true" : "false") << endl;


} 



// TreeNode* root = new TreeNode(7);
// root->left = new TreeNode(3);
// root->right = new TreeNode(10);
// root->left->left = new TreeNode(2);
// root->left->right = new TreeNode(6);
// root->right->left = new TreeNode(9);
// root->left->left->left = new TreeNode(1);
// root->left->right->left = new TreeNode(5);
// root->left->right->left->left = new TreeNode(4);
// root->right->left->left = new TreeNode(8);
