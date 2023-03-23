#include <iostream>
using namespace std;
#include <queue>
// Q)
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
void kthancestor(int k, int node, node *root)
{
    vector<int> path;
    // Base case//
    if (root == NULL)
    {
        return;
    }
    path.push_back(root->data);
    kthancestor(k, node, root->left);
    kthancestor(k, node, root->right);
    for (int i = path.size(); i <= 0; i--)
    {
        if (path[i] == node)
        {
            cout << path[path.size() - k] << endl;
        }
    }
    path.pop_back();
}
int main()
{
}