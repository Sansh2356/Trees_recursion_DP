#include <iostream>
// Q)To find the largest sum in the bloodline of a given tree//
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
void bloodline(node *&root, int sum, int &maxsum, int len, int maxlen)
{
    // Base case//
    if (root == NULL)
    {
        if (len > maxlen)
        {
            maxlen = len;
            maxsum = sum;
        }
        if (len == maxlen)
        {
            maxsum = sum;
        }
        sum = sum + root->data;
        // Call for traversal and increasing length for left part//
        bloodline(root->left, sum, maxsum, len + 1, maxlen);
        // Call for traversal and increasing length for right part//
        bloodline(root->right, sum, maxsum, len, maxlen);
    }
}
int main()
{
    node *root = NULL;
    int sum = 0;
    int maxsum = 0;
    int len = 0;
    int maxlen = 0;
    bloodline(root, sum, maxsum, len, maxlen);
    return maxsum;
}