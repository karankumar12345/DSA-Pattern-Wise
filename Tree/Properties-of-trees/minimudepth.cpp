#include<iostream>
#include<math.h>
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

int  MinDepth(Node* root){
if(root==NULL) return 0;
int leftDepth=MinDepth(root->left);
int rightDepth=MinDepth(root->right);
if(root->left==NULL && root->right==NULL){
    return 1;
}
if(root->left==NULL){
    return 1+rightDepth;
}
if(root->right==NULL){
    1+leftDepth;
}
return min(leftDepth,rightDepth);
}


int main(){
    Node* root=new Node(4);
    root->left=new Node(5);
    root->right=new Node(2);
    root->left->left=new Node(45);
    root->left->left->left=new Node(45);

    cout<<"MinDepth ";
     cout<<MinDepth(root)<<endl;
return 0;
}