//Inorder traversal of BST will always be in ascending order hence a sorting order//
//Q)Inorder predecessor and inorder successor//
//Q)VERY VERY IMPORTANT  <<------>>  Delete the given node of a tree//
#include<iostream>
using namespace std;
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
// Making of tree recursively//
node *buildtree(node *root)
{
    cout << "Enter data"
         << " " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        // Base case//
        return NULL;
    }
    cout << "Enter data to be inserted at left of"
         << " " << root->data << endl;
    root->left = buildtree(root->left);
    cout << "Enter data to be inserted at right of"
         << " " << root->data << endl;
    root->right = buildtree(root->right);
    return root;
}
int minival(node*root){
    node*temp=root;
    while(temp != NULL){
        temp = temp->right;
    }
    return temp->data;
}
int maxval(node*root){
    node*temp=root;
    while(temp != NULL){
        temp = temp->left;
    }
    return temp->data;
}
node*DeleteInBST(node*&root,int element){
    //Firstly we will traverse to that node which is to be deleted//
    //Base case//
    if(root == NULL){
        return root;
    }
    if(root->data == element){
        //Code for deletion//
        //If the given node has no node//
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        else if(root->left != NULL && root->right == NULL){
            node*temp = root->left;
            delete root;
            return temp;
        }
       else if(root->left == NULL && root->right != NULL){
            node*temp2 = root->right;
            delete root;
            return temp2;
       }
       else{
        int mini = minimval(root->right)-> data;
        root->data = minival;
        root->right = DeleteInBST(root->right,mini);
        return root;
       }
    }
    DeleteInBST(root->left,element);

    DeleteInBST(root->right,element);

    return root;
}
int main(){
/*
Deletion will have 4 cases namely-:
1)Node having two child 
2)Node having single child(right child)
3)Node having single child(left child)
4)Node having no child(Leaf node)

*/
int element;
cin>>element;
node*root=NULL;
DeleteInBST(root,element);
}