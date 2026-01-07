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
void nodesAtDistanceOfK(TreeNode *root, int k, vector<int> &ans, map<TreeNode *, int> &mpp, map<TreeNode *, TreeNode *> &parent)
{   if(!root)return;
    if (mpp[root] == 1)
        return;
    if (k == 0){
        mpp[root] = 1;
        ans.push_back(root->val);
        return;
    }
    mpp[root] = 1;
    nodesAtDistanceOfK(root->left, k - 1, ans, mpp, parent);
    nodesAtDistanceOfK(root->right, k - 1, ans, mpp, parent);
    nodesAtDistanceOfK(parent[root], k - 1, ans, mpp, parent);
    return;
}
TreeNode *buildSampleTree()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(5);
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
    vector<int> ans;
    map<TreeNode *, int> visited;
    map<TreeNode *, TreeNode *> parent;
    queue<TreeNode *> qu;
    qu.push(root);
    parent[root] = nullptr;
    while (!qu.empty())
    {
        int size = qu.size();
        while (size--)
        {
            TreeNode *top = qu.front();
            qu.pop();
            if (top->left)
            {
                parent[top->left] = top;
                qu.push(top->left);
            }
            if (top->right)
            {
                parent[top->right] = top;
                qu.push(top->right);
            }
        }
    }
    nodesAtDistanceOfK(root->left, 2, ans, visited, parent);
    print(ans);
    return 0;
}