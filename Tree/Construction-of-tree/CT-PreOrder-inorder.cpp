#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Definition for Binary Tree Node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to construct tree from inorder and preorder traversal
TreeNode* Construct(vector<int>& inorder, vector<int>& preorder, int& preIndex, int inorderStart, int inorderEnd) {
    if (inorderStart > inorderEnd) {
        return nullptr;
    }

    // Pick current element from preorder traversal
    int element = preorder[preIndex++];
    TreeNode* root = new TreeNode(element);

    // Find element in inorder traversal
    int position = -1;
    for (int i = inorderStart; i <= inorderEnd; i++) {
        if (inorder[i] == element) {
            position = i;
            break;
        }
    }

    // Recursive construction of left and right subtrees
    root->left = Construct(inorder, preorder, preIndex, inorderStart, position - 1);
    root->right = Construct(inorder, preorder, preIndex, position + 1, inorderEnd);

    return root;
}

// Wrapper function to build the tree
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preIndex = 0;
    return Construct(inorder, preorder, preIndex, 0, inorder.size() - 1);
}

// Function to print level-order traversal
void printLevelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->data << " ";

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

// Driver Code
int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};  // Example Preorder Traversal
    vector<int> inorder = {9, 3, 15, 20, 7};   // Example Inorder Traversal

    TreeNode* root = buildTree(preorder, inorder);

    cout << "Level Order Traversal: ";
    printLevelOrder(root);

    return 0;
}
