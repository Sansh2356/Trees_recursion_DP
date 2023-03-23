#include<iostream>
//Q)Building a BST from pre-order traversal//
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
int main(){

}