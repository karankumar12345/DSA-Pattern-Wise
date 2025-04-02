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

int  MaxDepth(Node* root){
    int ans=0;
    if(root==NULL){
        return 0;
    }
    int l=MaxDepth(root->left);
    int r=MaxDepth(root->right);
     ans=1+max(l,r);

return ans;
}


int main(){
    Node* root=new Node(4);
    root->left=new Node(5);
    root->right=new Node(2);
    root->left->left=new Node(45);
    root->left->left->left=new Node(45);

    cout<<"MaxiumDepth ";
     cout<<MaxDepth(root)<<endl;
return 0;
}