#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

int checkBalance(Node* root) {
    if (root == NULL) return 0;

    // Check the left subtree
    int left = checkBalance(root->left);
    if (left == -1) return -1; // If the left subtree is unbalanced, return -1

    // Check the right subtree
    int right = checkBalance(root->right);
    if (right == -1) return -1; // If the right subtree is unbalanced, return -1

    // Check if the current node is balanced
    if (abs(left - right) > 1) return -1; // If the height difference is greater than 1, it's unbalanced

    // Return the height of the current subtree
    return max(left, right) + 1;
}

bool isBalanced(Node* root) {
    return checkBalance(root) != -1; // If checkBalance returns -1, the tree is unbalanced
}

int main() {
    Node* root = new Node(4);
    root->left = new Node(4);
    root->left->left = new Node(5); // Correctly assign the left child of the left node
    root->right = new Node(5);

    if (isBalanced(root)) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}
