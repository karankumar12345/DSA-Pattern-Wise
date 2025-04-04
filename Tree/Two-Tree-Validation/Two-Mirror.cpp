

#include <iostream>
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

// Function to check if two trees are the same
int  CheckSameTree(Node* p, Node* q) {
    if (p == NULL && q == NULL) return true;  // Both are NULL -> same tree
    if (p == NULL || q == NULL) return false; // One is NULL -> not same
    if (p->data != q->data) return false;  
    // Check left and right subtrees
    return CheckSameTree(p->left, q->left) && CheckSameTree(p->right, q->right);
}

int main() {
    // Creating first tree
    Node* tree1 = new Node(1);
    tree1->left = new Node(2);
    tree1->right = new Node(3);
    tree1->left->left = new Node(4);
    tree1->left->right = new Node(5);
    tree1->right->left = new Node(6);
    tree1->right->right = new Node(7);

    // Creating second tree (identical to tree1)
    Node* tree2 = new Node(1);
    tree2->left = new Node(2);
    tree2->right = new Node(3);
    tree2->left->left = new Node(4);
    tree2->left->right = new Node(5);
    tree2->right->left = new Node(6);
    tree2->right->right = new Node(7);

    // Check if both trees are the same
    if (CheckSameTree(tree1, tree2)) {
        cout << "Both trees are identical." << endl;
    } else {
        cout << "Trees are not identical." << endl;
    }

    return 0;
}
