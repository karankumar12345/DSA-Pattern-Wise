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

void InOrder(Node* root){
    if(root==NULL){
        return ;
    }
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
   
}


int main(){
    Node* root=new Node(3);
    root->left=new Node(4);
    root->right=new Node(5);

    cout<<"Inorder Traversal"<<endl;
    InOrder(root);
}