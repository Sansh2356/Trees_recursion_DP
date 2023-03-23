#include<vector>
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
void inorder(node*root,vector<node*>&v){
    if(root == NULL){
        return;
    }
    inorder(root->left,v);
    v.push_back(root);
    inorder(root->right,v);
}
node*inordertoBST(int s,int e,vector<node*>&v){
//Base case//
if(s > e){
    return NULL;
}
//Finding out of mid//
int mid=s+e/2;
//Creation of node and storing of value of the mid node//
node*newnode=new node(v[mid]->data);
//Traversal along the sorted array//
newnode->left=(s,mid-1,v);
newnode->right=(mid+1,e,v);
return newnode;

}

int main(){
    node*root=NULL;
    /*
    1)Step-1 To get vector of sorted order by traversing inorder
    2)Step-2 To find out mid of that particular sorted vector
    3)Step-3 To make tree
    */
   vector<node*>v;
   inorder(root,v);
   inordertoBST(0,v.size()-1,v);

}