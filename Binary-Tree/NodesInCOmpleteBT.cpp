#include <bits/stdc++.h>
using namespace std;
// Time : O(log(N)^2)
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
int LeftHeight(TreeNode *root)
{
    int ht = 0;
    TreeNode *temp = root;
    while (temp->left){
            temp = temp->left;
            ht++;
    }
    return ht ;
}
int RightHeight(TreeNode *root)
{
    int ht = 0;
    TreeNode *temp = root;
    while(temp->right){
            temp = temp->right;
            ht++;
    }
    return ht;
}
int Nodes(TreeNode *root)
{   if(!root)return 0;
    int lh = LeftHeight(root);
    int rh = RightHeight(root);
    if (lh == rh)
        return pow(2, lh + 1) - 1;
    return 1 + Nodes(root->left) + Nodes(root->right);
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
    root->left->left->left = new TreeNode(8);
    root->left->left->left->left = new TreeNode(9);
    return root;
}
int main()
{
    TreeNode *root = buildSampleTree();
    cout<<"Nodes :" << Nodes(root);
    return 0;
}