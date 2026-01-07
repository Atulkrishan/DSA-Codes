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
int maximumWidth(TreeNode *root)
{
    TreeNode *temp = root;
    queue<pair<TreeNode *, int>> qu;
    qu.push({root, 1});
    int maxWidth = 0;
    while (!qu.empty())
    {
        int size = qu.size();
        int base = 0;
        for (int i = 0; i < size; i++)
        {
            TreeNode *node = qu.front().first;
            int idx = qu.front().second;
            qu.pop();
            if (i == 0)
                base = idx;
            if (i == size - 1)
                maxWidth = max(maxWidth, idx - base + 1);
            if (node->left)
            {
                qu.push({node->left, 2 * idx});
            }
            if (node->right)
            {
                qu.push({node->right, 2 * idx + 1});
            }
        }
    }
    return maxWidth;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    cout << maximumWidth(root);
    return 0;
}