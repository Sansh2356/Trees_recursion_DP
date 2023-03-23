#include<iostream>
using namespace std;
#include<vector>
class node{
    public:
    int data;
    int left;
    int right;
    node(int f){
        this->data=f;
        this->left=NULL;
        this->right=NULL;
    }
};
//Q)To print nodes data in the sequence of boundary traversal//
node*leftnode(node*root){
    vector<int>ans;
    ans.push_back(root->data);
    //Base case//
    if(root->left && root->right == NULL){
        return;
    }
    if(root->left){
       root=leftnode(root->left);
    }
    else{
     root=leftnode(root->right);
    }
}
node*leafnode(node*root,vector<int>&ans){
if(root==NULL){
    return;
}
if(root->left && root->right == NULL){
    ans.push_back(root->data);
    return;
}
leafnode(root->left);
leafnode(root->right);
}
node*rightnode(node*root,vector<int>&ans){
    //Base case//
    if(root->right && root->left == NULL){
        return;
    }
if(root->right){
    root=root->right
}
ans.push_back(root->data);
}

vector<int>boundarytraversal(node*root){
    //Firstly travese the left nodes excluding the leaf nodes//
     leftnode(root);
     //Secondly traverse through the leaf nodes//
     leafnode(root);
     //Traverse through the right nodes//
     rightnode(root);
}
int main(){
    node*root;
    boundarytraversal(root);

}