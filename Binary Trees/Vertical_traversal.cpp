#include <iostream>
#include <queue>
#include <map>
using namespace std;
//Q)Top-view traversal of a tree//
int main()
{
    vector<int> ans;
    // Base case//
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> topnode;
    queue<pair<node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<node *, int> temp = q.front();
        node *frontnode = temp.first;
        int hd = temp.second;
        // Check for single mapping for a unique HD//
        if (topnode.find(hd) == topnode.end())
        {
            topnode[hd] = temp->data;
        }
        if (frontnode->left)
        {
            q.push(make_pair(frontnode->left, hd - 1));
        }
        if (front->right)
        {
            q.push(make_pair(frontnode->right, hd + 1));
        }
    }
    for(auto i:topnode){
        ans.push_back(i.second);
    }
}