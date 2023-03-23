#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int f)
    {
        this->data = f;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *BuildTree(Node *&root)
{
    cout << "Enter the data you want to create a Node for:" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    // Base Case//
    if (data == -1)
    {
        return root;
    }
    cout << "The data you want to enter at left of :" << data << endl;
    int leftdata;
    cin >> leftdata;
    root->left = BuildTree(root->left);
    cout << "The data you wnat to enter at right of:" << data << endl;
    int rightdata;
    cin >> rightdata;
    root->right = BuildTree(root->right);
    return root;
}
int main()
{
    Node *root = NULL;
    BuildTree(root);
}