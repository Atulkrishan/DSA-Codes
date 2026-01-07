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
void postOrderIterative(TreeNode *root, vector<int> &ans)
{
    stack<TreeNode *> st;
    TreeNode *curr = root;
    TreeNode *prev = nullptr;
    while (curr || !st.empty())
    {
        while (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        if (curr->right == nullptr || curr->right == prev)
        {
            st.pop();
            ans.push_back(curr->val);
            prev = curr;
            curr = nullptr;
        }
        else
        {
            curr = curr->right;
        }
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
    vector<int> inOrder;
    postOrderIterative(root, inOrder);
    print(inOrder);
    return 0;
}