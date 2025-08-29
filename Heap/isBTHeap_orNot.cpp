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

// is given binary tree a max-heap or not
// CBT - complete binary tree

int countNo_ofNodes(TreeNode* root){
    if(root == NULL) return 0;

    int left = countNo_ofNodes(root->left);
    int right = countNo_ofNodes(root->right);
    return 1 + left + right;
}

bool isCBT(TreeNode* root, int index, int totalCount){
    if(root == NULL) return true;

    if(index >= totalCount) return false;
    else {
        int left = isCBT(root->left, 2 * index + 1, totalCount);
        int right = isCBT(root->right, 2 * index + 2, totalCount);
        return left && right;
    }
}

bool isMaxOrder(TreeNode* root){
    // leaf node
    if(root->left == NULL && root->right == NULL) return true;

    // right is null means just comparing root with left of root
    if(right == NULL) {
        return (root->val > root->left->val);
    }
    else {      // both left and right of root is there
        bool left = isMaxOrder(root->left);
        bool right = isMaxOrder(root->right);

        return (left && right && (root->val > root->left->val && root->val > root->right->val));
    }
}

bool isHeap(TreeNode* root){
    int totalCount = countNo_ofNodes(root);
    int index = 0;
    return isCBT(root, 0, totalCount) && isMaxOrder(root);

}

int main(){

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    bool isBtHeap = isHeap(root);
    if(isBtHeap == 1) cout << "This Binary Tree is a Heap";
    else cout << "This Binary Tree is not a heap";
    
} 







// ## ✅ What You're Currently Doing (0-based indexing):

// ### Binary Tree as Array (0-based):

// * For a node at index `i`:

//   * **Left child:** `2 * i + 1`
//   * **Right child:** `2 * i + 2`

// Your current function:

// ```cpp
// bool isCBT(TreeNode* root, int index, int totalCount) {
//     if (root == NULL) return true;

//     if (index >= totalCount) return false;

//     bool left = isCBT(root->left, 2 * index + 1, totalCount);
//     bool right = isCBT(root->right, 2 * index + 2, totalCount);

//     return left && right;
// }
// ```

// This is correct for **0-based indexing**, and your `countNo_ofNodes()` function gives `totalCount` correctly as `n`.

// So your final call:

// ```cpp
// return isCBT(root, 0, totalCount);
// ```

// is valid.

// ---

// ## 🔄 How to Convert to **1-based indexing**:

// In **1-based indexing**, the child relationships become:

// * For a node at index `i`:

//   * **Left child:** `2 * i`
//   * **Right child:** `2 * i + 1`

// So the function would change as follows:

// ```cpp
// bool isCBT(TreeNode* root, int index, int totalCount) {
//     if (root == NULL) return true;

//     if (index > totalCount) return false;

//     bool left = isCBT(root->left, 2 * index, totalCount);
//     bool right = isCBT(root->right, 2 * index + 1, totalCount);

//     return left && right;
// }
// ```

// And the function call becomes:

// ```cpp
// int totalCount = countNo_ofNodes(root);
// return isCBT(root, 1, totalCount);  // Start with index 1
// ```

// ---

// ## 🧠 Summary:

// | Feature               | 0-Based Indexing             | 1-Based Indexing             |
// | --------------------- | ---------------------------- | ---------------------------- |
// | Left Child            | `2 * i + 1`                  | `2 * i`                      |
// | Right Child           | `2 * i + 2`                  | `2 * i + 1`                  |
// | Root Index            | `0`                          | `1`                          |
// | `index >= totalCount` | Yes                          | No, use `index > totalCount` |
// | Initial Call          | `isCBT(root, 0, totalCount)` | `isCBT(root, 1, totalCount)` |

