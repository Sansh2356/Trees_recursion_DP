#include <iostream>
using namespace std;
#include <queue>
// Q)To build a tree using inorder,preorder traversals//
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
int findposition(int in[], int data, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (in[i] == data)
        {
            return i;
        }
    }
}

node *solve(int pre[], int in[], int index, int sizeofinorder, node *root,int preorderend,int preorderstart)
{
    // Base case//
    if (inorderindex > size || preorderstart > preorderend)
    {
        return NULL;
    }
    index = 0;
    node *root = new node(pre[index++]);
    // Comparison with inorder array to find out the position of that particular root of preorder array//
    int position = findposition(in, root->data, sizeofinorder);
    // Recursive calls//
    root->left = (pre, in, index, sizeofinorder, root->left);
    root->right = (pre, in, index, sizeofinorder, root->right);
}

int main()
{
    int pre[5];
    int in[5];
    int index;
    int sizeofinorder;
    node *root = NULL;
    int preorderstart=0;
    int preorderend;
    solve(pre, in, index, sizeofinorder, root,preorderend,preorderstart);
}