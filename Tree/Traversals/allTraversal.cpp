#include<iostream>>
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


void TreeTraversal(Node* root,bool pre,bool in,bool post){
    if(root==NULL) return ;

    if(pre) cout<<root->data<<" ";
    TreeTraversal(root->left,pre,in,post);
    if(in) cout<<root->data<<" ";
    TreeTraversal(root->right,pre,in,post);
    if(post) cout<<root->data<<" ";
}


int main(){
    Node* root=new Node(4);
    Node* root->left=new Node(5);
    Node* root->right=new Node(4);

    cout<<"PreOrderr" <<end;
    TreeTraversal(root,true,false,false);
    cout<<endl;
}