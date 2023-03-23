#include<iostream>

using namespace std;
//Binary search tree is a type of special binary tree in which the child nodes of the root for the left subtree will always be lesser than the 
//root node and the child nodes for the right tree will always be greater than the root's data//
class node{
    public:
    int data;
    node*right;
    node*left;
    node(int f){
        this->data=f;
        this->left=NULL;
        this->right=NULL;
    }
};
node*insertinbst(node*&root,int data){
    //Base case//
    if(data==-1){
        root=NULL;
        return root;
    }
    if(root==NULL){
        root=new node(data);
        return root;
    }
    //If the entered element is greater than the root element than we will add it to right side and if it is lesser than we will add it to left side//
    int data2;
    cin>>data2;
    data=data2;
    
        if(data==-1){
        root=NULL;
        return root;
    }
    if(data > root->data){
      
       root->left= insertinbst(root->left,data);
    }
    if(data < root->data){
       
        root->right=insertinbst(root->right,data);
    }
    return root;


}
int main(){
    node*root=NULL;
    int data;
    cout<<"Enter data to be inserted in BST"<<endl;
    cin>>data;
    insertinbst(root,data);
}