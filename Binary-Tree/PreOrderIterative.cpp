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
void preOrderIterative(TreeNode *root)
{
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        TreeNode* top = st.top();
        st.pop();
        if(top->right)st.push(top->right);
        if(top->left)st.push(top->left);
        cout<<top->val<<" ";
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
    return root;
}

int main()
{
    TreeNode *root = buildSampleTree();
    preOrderIterative(root);
    return 0;
}