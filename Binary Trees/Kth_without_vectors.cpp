#include <iostream>
using namespace std;
#include <queue>
// Q)To find the depth of a tree given by the maximum of the lowermost leaf node from either right node or left node//
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
node *kthancestor(node *root, int n, int k)
{
    // Base case//
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n)
    {
        return root;
    }
    node *leftans = kthancestor(root->left, n, k);
    node *rightans = kthancestor(root->right, n, k);
    if (leftans == NULL && rightans == NULL)
    {
        return NULL;
    }
    if (leftans != NULL && rightans = NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
    }
    if (leftans == NULL && rightans != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }

        return root;
    }
}
int main()
{
    node*root=NULL;
    int n,k;
    cin>>n>>k;
    kthancestor(root,n,k);
}