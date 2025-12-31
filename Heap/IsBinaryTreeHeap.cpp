#include <bits/stdc++.h>
using namespace std;
class TreeNode{
    // Time : O(n) Space : O(logn)
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
TreeNode *buildSampleTree()
{
    // heap allocation of memeory
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    return root;
}
int TotalNodes(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + TotalNodes(root->left) + TotalNodes(root->right);
}
bool isBnaryTreeHeap(TreeNode *node, int total, int idx)
{
    if(!node)return true;
    if (idx >= total)
        return false;
    if ((node->left && node->left->val > node->val) || (node->right && node->right->val > node->val))
        return false;
    return isBnaryTreeHeap(node->left, total, 2 * idx + 1) && isBnaryTreeHeap(node->right, total, 2 * idx + 2);
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
    int totalnodes = TotalNodes(root);// O(n)
    cout<<"isBnaryTreeHeap : "<<(bool)isBnaryTreeHeap(root,totalnodes,0);// O(n)
    return 0;
}