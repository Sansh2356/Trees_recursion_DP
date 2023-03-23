#include <iostream>
using namespace std;
#include <queue>
//Q)To find the depth of a tree given by the maximum of the lowermost leaf node from either right node or left node//
class node
{
public:
    int data;
    node *left;
    node *right;
    node(int f)
    {
        this->data = f;
        this->left = NULL;
        this->right = NULL;
    }
};
node *BuildTree(node *root)
{
    cout << "Enter data to be inserted" << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data==-1)
    {
        return NULL;
    }
    // left traversal//
    cout << "Enter data to be inserted at left of:"
         << " " << root->data << endl;
    root->left = BuildTree(root->left);
    cout << "Enter data to be inserted at right of:"
         << " " << root->data << endl;
    root->right = BuildTree(root->right);
    return root;
}
//Types of traversals will include post order,pre order and inorder//
//LRN,NLR,LNR//
int Depth(node*&root){
    //Entire left node traversal and then right node traversal will be done//
    //Base case//
    int depth=0;
    if(root==NULL){
        return depth+1;
    }
   Depth(root->left);
   root=root->left;
   Depth(root->right);
   root=root->right;
   
}
int height(node*root){
    //Base case//
    if(root==NULL){
        return 0;
    }
    //Traverse through left sides//
    int left=height(root->left);
     //Traverse through right sides//
    int right=height(root->right);
    int ans=max(left,right);
    return ans;
}
int main()
{
    node *root = NULL;
    BuildTree(root);
    Depth(root);
}