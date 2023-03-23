#include <iostream>
using namespace std;
#include <queue>
#include <map>
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
    if (data == -1)
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
node *lca(node *&root, node *n1, node *n2)
{
    // Base case//
    if (root = NULL)
    {
        //Accoding to the tree recursive calling we have to return value and compare it along with right and left side ans and return a output on the basis of that//
        return NULL;
    }
    //The value will come out for left and right at two points namely when eithe right or left are keynodes or the node is null//
    if (root == n1 || root == n2)
    {
        return root;
    }
    //Calling for left part//
    node *leftans = lca(root->left, n1, n2);
    //Calling for right part//
    node *rightans = lca(root->right, n1, n2);
    if (leftans == NULL && rightans == NULL)
    {
        return NULL;
    }
    else if (leftans != NULL && rightans == NULL)
    {
        return leftans;
    }
    else if (rightans != NULL && leftans == NULL)
    {
        return rightans;
    }
    else if (leftans != NULL && rightans != NULL)
    {
        return root;
    }
    return root;
}
int main()
{
    node *root = NULL;
    node *n1 = NULL;
    node *n2 = NULL;
    lca(root, n1, n2);
}