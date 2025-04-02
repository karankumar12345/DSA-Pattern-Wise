#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// PreOrder Traversal function
void PreOrder(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";  // Visit root
    PreOrder(root->left);       // Traverse left subtree
    PreOrder(root->right);      // Traverse right subtree
}

int main() {
    // Correct object creation and memory allocation
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);

    cout << "PreOrder Traversal:" << endl;
    PreOrder(root);

    // Free dynamically allocated memory
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
