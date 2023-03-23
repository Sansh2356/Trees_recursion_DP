#include <iostream>
#include <queue>
#include <string>
#include <stack>
#include <vector>
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
node *buildtree(node *root)
{
    cout << "Enter data" << endl;
    int data;
    cin >> data;
    root = new node(data);
    // base case//
    if (data == -1)
    {
        return NULL;
    }
    cout << "Enter data to be inserted at left of:" << root->data << endl;
    root->left = buildtree(root->left);
    cout << "Enter data to be inserted at right of:" << root->data << endl;
    root->right = buildtree(root->right);
    return root;
}
vector<int> zigzag(node *&root, int size)
{
    vector<int> result;
    vector<int> ans[size];
    queue<node *> q;
    q.push(root);
    bool lefttoright = true;
    while (!q.empty())
    {
        vector<int> ans[size];
        for (int i = 0; i < size; i++)
        {
            node *front = q.front();
            q.pop();
            int index = lefttoright ? i : size - i - 1;
            ans[index] = front->data;
            if (front->left)
            {
                q.push(front->left);
            }
            if (front->right)
            {
                q.push(front->right);
            }
        }
        lefttoright = !lefttoright;
    }
    for (int l = 0; l < size; l++)
    {
        result.push_back(ans[l]);
    }
    return result;
}

int main()
{
    node *root = NULL;
    buildtree(root);
    buildtree(root);
}