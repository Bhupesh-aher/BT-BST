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

void inorderTraversal(TreeNode* root, vector<int> &inorder){
    if(root == NULL) return;
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->val);
    inorderTraversal(root->right, inorder);
}
bool findTarget(TreeNode* root, int k) {
    vector<int> inorder;
    inorderTraversal(root, inorder);
    int i = 0, j = inorder.size() - 1;
    while(i < j){
        if(inorder[i] + inorder[j] == k) return true;
        else if(inorder[i] + inorder[j] < k) i++;
        else j --;
    }
    return false;
}

// TC - O(N) + O(N) 
// SC - O(N)



// in previous problem BST iterator we done the inorder trvaersal where 
// we push the element in stack and than we go right of the node and from that right node we again go to left nodes and
// push them in the stack
// so it was right and then all left nodes - to get the next() element
// here we will do opposite - so by doing this we will get the before() element 
// left and then all right nodes
// when we pick st.top() we will go left and then all right nodes 
// we will use both the things here next() and before()




class BSTIterator {
    stack<TreeNode*> st;
    bool reverse = true;
    // reverse -> true -> before
    // reverse -> false -> next
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    private: 
    void pushAll(TreeNode* node){
        for(; node != NULL; ){
            st.push(node);
            if(reverse == true){
                node = node->right;
            }
            else node = node->left;
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root, false);  // next
        BSTIterator r(root, true);   // before

        int i = l.next();
        int j = r.next(); // r.before()

        while(i < j){
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};

// TC - O(N) 
// SC - O (h) * 2

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(7);

    cout << "Inorder of BST - ";
    printInorder(root);
    cout << endl;

    int k = 9;
    bool exists = findTarget(root, k);

    if (exists)  cout << "Pair with sum " << k << " exists." << endl;
    else cout << "Pair with sum " << k << " does not exist." << endl;
    

} 



