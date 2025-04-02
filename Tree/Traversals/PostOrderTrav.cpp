#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        right=left=NULL;
    }
};

void PostOrder(Node* root){
    if(root==NULL){
        return ;
    }
    PostOrder(root->right);
    PostOrder(root->right);
    cout<<root->data<<" ";
}


int main(){
    Node* root=new Node(4);
    root->left=new Node(5);
    root->right=new Node(2);

    cout<<"Post Order Traversal";
    PostOrder(root);
return 0;
}