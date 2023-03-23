#include <iostream>
#include <queue>
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
        this->right = NULL;
        this->left = NULL;
    }
};

Node *BuildTree(Node *root)
{
    // Recursive check for insertion of data//
    cout << "Enter the number for insertion node:" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    if (data == -1)
    {
        // base  case//
        return NULL;
    }
    cout << "Enter data for insertion at left of" << data << endl;
    root->left = BuildTree(root->left);
    cout << "Enter data for insertion at right of" << data << endl;
    root->right = BuildTree(root->right);
    return root;
}
void LevelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() != 0)
    {
        Node *currnode = q.front();
        cout << currnode->data << endl;
        q.pop();
        if (q.front() == NULL)
        {
            cout << endl;
            q.pop();
            if (q.size() != 0)
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << currnode->data << endl;
            if (currnode->left != NULL)
            {
                q.push(currnode->left);
            }
            if (currnode->right)
            {
                q.push(currnode->right);
            }
        }
    }
}
void inorder(Node *root)
{
    // Base case//
    // LNR//
    if (root = NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}
void preorder(Node *root)
{
    // Base case//
    // NLR//
    if (root = NULL)
    {
        return;
    }
    cout << root->data << endl;
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node *root)
{
    // Base case//
    // LRN//
    if (root = NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->data << endl;
}
// Buliding tree from a given level order input//
Node *build2(Node *&root)
{
    queue<Node *> q;
    int data;
    cout << "Enter data" << endl;
    cin >> data;
    root = new Node(data);
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        cout << "Enter data to be inserted at the left node of"
             << " " << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new Node(leftdata);
            q.push(temp->left);
        }

        cout << "Enter data to be inserted at the right node of"
             << " " << temp->data << endl;
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new Node(rightdata);
            q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = NULL;
    BuildTree(root);
}