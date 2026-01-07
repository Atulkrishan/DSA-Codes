#include <bits/stdc++.h>
using namespace std;
// The diameter of a binary tree is the length of the longest path between any two nodes in the tree.
// This path may or may not pass through the root.
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
int height(TreeNode *root)
{
    if (!root)
        return 0;
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}
void Diameter(TreeNode *root,int &ans)
{
    if (!root)return;
    int left = height(root->left);
    int right = height(root->right);
    ans = max(left+right,ans);
    Diameter(root->left,ans);
    Diameter(root->right,ans);
}
TreeNode *buildSampleTree()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    return root;
}
void print(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}
int main()
{
    TreeNode *root = buildSampleTree();
    int ans = 0;
    Diameter(root,ans);
    cout<<ans;
    return 0;
}