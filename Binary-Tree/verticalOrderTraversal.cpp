#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        this->left = nullptr;
        this->right = nullptr;
        this->val = x;
    }
};
void verticalOrderTraversal(TreeNode *root, vector<vector<int>> &ans)
{
    queue<pair<TreeNode *, pair<int, int>>> qu;
    qu.push({root, {0,0,}});
    map<int, map<int, multiset<int>>> mpp;
    while (!qu.empty())
    {
        auto itr = qu.front();
        qu.pop();
        TreeNode *node = itr.first;
        int x = itr.second.first;
        int y = itr.second.second;
        mpp[x][y].insert(node->val);
        if (node->left)
        {
            qu.push({node->left, {x - 1, y + 1}});
        }
        if (node->right)
        {
            qu.push({node->right, {x + 1, y + 1}});
        }
    }
    for (auto it : mpp)
    {
        vector<int> temp;
        for (auto itr2 : it.second)
        {
            temp.insert(temp.end(), itr2.second.begin(), itr2.second.end());
        }
        ans.push_back(temp);
    }
}
TreeNode *buildSampleTree()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}
void print(vector<vector<int>> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    TreeNode *root = buildSampleTree();
    vector<vector<int>> inOrder;
    verticalOrderTraversal(root, inOrder);
    print(inOrder);
    return 0;
}