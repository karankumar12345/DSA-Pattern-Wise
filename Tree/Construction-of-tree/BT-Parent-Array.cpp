#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to create a binary tree from a parent array
Node* createTree(vector<int> parent) {
    int n = parent.size();
    vector<Node*> v(n);

    // Step 1: Create nodes
    for (int i = 0; i < n; i++) {
        v[i] = new Node(i);
    }

    Node* root = nullptr;

    // Step 2: Establish Parent-Child Relationships
    for (int i = 0; i < n; i++) {
        if (parent[i] == -1) {
            root = v[i];  // Root node
        } else {
            if (v[parent[i]]->left == nullptr) {
                v[parent[i]]->left = v[i];
            } else {
                v[parent[i]]->right = v[i];
            }
        }
    }

    return root;  // Return the fully constructed tree
}

// Function to print tree in level order
void printLevelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        cout << node->data << " ";

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

// Driver Code
int main() {
    vector<int> parent = {-1, 0, 0, 2, 2}; // Example Input

    Node* root = createTree(parent);

    cout << "Level Order Traversal: ";
    printLevelOrder(root);

    return 0;
}
