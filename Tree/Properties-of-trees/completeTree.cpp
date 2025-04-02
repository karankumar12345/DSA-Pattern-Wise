#include<iostream>
#include<math.h>
using namespace std;
 

struct  Node
{
   int data;
   Node* left;
   Node* right;
    
   Node(int val){
    data=val;
    left=right=NULL;
   }
};

void inorder(Node* curr,int &count){
    if(curr==NULL){
        return ;
    }
    count++;
    inorder(curr->left,count);
    inorder(curr->right,count);
}
int CountNodes(Node* root){
    int count=0;
    inorder(root,count);
    return count;
}

int main(){
    Node* root=new Node(4);
    root->left=new Node(5);
    root->right=new Node(2);
    root->left->left=new Node(45);
    root->left->left->left=new Node(45);

    cout<<"Complete Tree ";
     cout<<CountNodes(root)<<endl;
return 0;
}