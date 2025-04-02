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

int heightAndDiameter(Node* root,int &diameter){
    if(root==NULL){
        return 0;
    }
    int leftHeight=heightAndDiameter(root->left,diameter);
    int rightHeight=heightAndDiameter(root->right,diameter);
    diameter=max(diameter,leftHeight+rightHeight);
    return max(rightHeight,leftHeight)+1;
}
int diameterOfBinaryTree(Node* root) {
    int diameter = 0;  // Initialize the diameter to 0
    heightAndDiameter(root, diameter);  // Update the diameter during the traversal
    return diameter;
}

int main(){
    Node* root=new Node(4);
    root->left=new Node(5);
    root->right=new Node(2);
    root->left->left=new Node(45);
    root->left->left->left=new Node(45);

    cout<<"Depth ";
     cout<<diameterOfBinaryTree(root)<<endl;
return 0;
}