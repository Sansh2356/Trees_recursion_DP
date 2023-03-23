#include <iostream>
#include <queue>
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
// Making of tree recursively//
node *buildtree(node *root)
{
    cout << "Enter data"
         << " " << endl;
    int data;
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        // Base case//
        return NULL;
    }
    cout << "Enter data to be inserted at left of"
         << " " << root->data << endl;
    root->left = buildtree(root->left);
    cout << "Enter data to be inserted at right of"
         << " " << root->data << endl;
    root->right = buildtree(root->right);
    return root;
}
/*
// Making of tree from level-order//
void levelbuild(node *&root)
{
    queue<node *> q;
    cout << "Enter data" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "Enter data to be inserted at left of"
             << " " << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout << "Enter data to be inserted at right of"
             << " " << temp->data << endl;
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}
*/
// Level order traversal//

void Lot(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        cout << temp->data << endl;
        q.pop();
        if (temp == NULL)
        {
          //  q.pop();
            cout << endl;
          //  q.pop();
            // if (q.empty())
            // {
            //     break;
            // }
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
           // cout << temp->data << endl;
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void inorder(node*root){
    //LNR//
    if(root == NULL){
        return;
    }
inorder(root->left);
cout<<root->data<<endl;
inorder(root->right);
}
void preorder(node*root){
    //NLR//
    if(root == NULL){
        return;
    }
cout<<root->data<<endl;
preorder(root->left);
preorder(root->right);
}
void postorder(node*root){
    //LRN
    if(root == NULL){
        return;
    }
cout<<root->data<<endl;
postorder(root->left);
postorder(root->right);
cout<<root->data<<endl;
}

int main()
{
    node *root = NULL;
   root=buildtree(root);
  Lot(root);
}