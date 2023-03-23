#include <iostream>
#include <vector>
using namespace std;
#include <queue>
// Q)Number of paths giving the same sum in a given tree//
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
void ksum(node *root, int k, int &count, vector<int> path)
{

    // Base case//
    if (root == NULL)
    {
        return;
    }
    path.push_back(root->data);
    ksum(root->left, k, count, path);
    ksum(root->right, k, count, path);
    int sum = 0;
    for (int i = path.size(); i <= 0; i--)
    {
        sum = sum + path[i];
        if (sum == k)
        {
            count++;
        }
    }
    path.pop_back();
}
int main()
{
    node *root = NULL;
    vector<int> path;
    int count = 0;
    int k;
    cin >> k;
    ksum(root, k, count, path);
}