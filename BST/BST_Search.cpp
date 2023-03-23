/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/

bool searchInBST(BinaryTreeNode<int> *root, int x)
{
    // Write your code here.
    bool istrue = false;
    // Base case//
    if (root == NULL)
    {
        return istrue;
    }
    if (root->data == x)
    {
        istrue = true;
        return istrue;
    }
    // Recursive call for left node//
    bool leftans = searchInBST(root->left, x);
    // Recursive call for right node//
    bool rightans = searchInBST(root->right, x);
    if (leftans == false && rightans == true || leftans == true && rightans == false)
    {
        istrue = true;
    }
    else
    {
        istrue = false;
    }
    return istrue;
}
/*
    Can also be solved iteratively using a while loop
    1)Initializing a variable using temp variable by root node
    2)Running a while loop till the time the root reaches the null node
    node*BSTsearch(node*&root,int x){
    while(temp != NULL){
        if(temp == NULL){
            return true;
        }
        else if(temp->data > x){
            temp=temp->left;
        }
        else if(temp->data < x){
            temp = temp->right;
        }
        
    }
    }

*/