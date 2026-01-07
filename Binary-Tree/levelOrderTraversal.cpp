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
void levelOrderTraversal(TreeNode *root)
{
    queue<TreeNode *> qu;
    qu.push(root);
    while (!qu.empty()){
        int size = qu.size();
        while(size--){
            TreeNode* top = qu.front();
            qu.pop();
            if(top->left){
                qu.push(top->left);
            }
            if(top->right){
                qu.push(top->right);
            }
            cout<<top->val<<" ";
        }
        cout<<endl;
    }
}
TreeNode *buildSampleTree()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    return root;
}

int main()
{
    TreeNode *root = buildSampleTree();
    levelOrderTraversal(root);
    return 0;
}