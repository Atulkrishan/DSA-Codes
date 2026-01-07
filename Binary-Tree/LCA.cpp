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
TreeNode* LCA(TreeNode *root,TreeNode* node1 , TreeNode* node2)
{
    if(!root)return nullptr;
    if(root == node1 || root == node2)return root;
    TreeNode* left = LCA(root->left,node1,node2);
    TreeNode* right = LCA(root->right,node1,node2);
    if(left && right){
        return root;
    }
    else if(left || right){
        return left?left:right;
    }
    else{
        return nullptr;
    }
}
int main()
{
    vector<int>ans;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    cout<<LCA(root,root->left->left,root->left)->val;
    return 0;
}