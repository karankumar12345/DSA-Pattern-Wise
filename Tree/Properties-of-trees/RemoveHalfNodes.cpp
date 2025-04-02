#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

Node* RemoveHalfNodes(Node* root){
    if(root==NULL) return NULL;
    root->left=RemoveHalfNodes(root->left);
    root->right=RemoveHalfNodes(root->right);
    if(root->left && !root->right) return root->left;
    else if(root->right && !root->left) return root->right;
    else return root;
}
void InOrder(Node* root) {
    if (root == nullptr) return;
    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}
int main(){
    Node* root=new Node(3);
    root->left=new Node(4);
    root->right=new Node(5);
    root->left->left=new Node(45);
    Node* fresh=RemoveHalfNodes(root);
    InOrder(fresh);

}