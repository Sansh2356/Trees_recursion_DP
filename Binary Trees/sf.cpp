#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *right;
    node *left;
    node(int f)
    {
        this->data = f;
        this->left = NULL;
        this->right = NULL;
    }
};
node *Buildtree(node *root)
{
    // Root node allotment//
    int value;
    cout << "Enter data" << endl;
    cin >> value;
    node *curr = new node(value);
    root = curr;
    // Base case//
    if (value == -1)
    {
        return NULL;
    }
    // Recursive call for making left tree and then right tree//
    cout << "enter for the insertion at left of"
         << " " << value << endl;
    curr->left = Buildtree(curr->left);
    cout << "enter for the insertion at right of"
         << " " << value << endl;
    curr->right = Buildtree(curr->right);
    return root;
}
node *levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    cout << q.front()->data << endl;
    while (!q.empty())
    {
        node*temp=q.front();
        q.pop();
        if (q.front() == NULL)
        {
            cout << endl;
           
            if (q.size() == 0)
            {
                break;
            }
            else if (q.size() != 0)
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << q.front()->data << endl;
            if (root->left)
            {
                q.push(root->left);
            }
            if (root->right)
            {
                q.push(root->right);
            }
        }
    }
}
int main()
{
    // level order,pre-order,post-order,in-order//
    node *root = NULL;
    root = Buildtree(root);
    levelOrderTraversal(root);
}