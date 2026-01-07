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
void topView(TreeNode *root,vector<int>&ans)
{
    map<int,TreeNode*>mpp;
    queue<pair<int,TreeNode*>>qu;
    qu.push({0,root});
    while(!qu.empty()){
        int size = qu.size();
        while(size--){
            TreeNode* node = qu.front().second;
            int x = qu.front().first;
            qu.pop();
            if (mpp.find(x) == mpp.end()) {
                mpp[x] = node;
            }
            if(node->left){
                qu.push({x-1,node->left});
            }
            if(node->right){
                qu.push({x+1,node->right});
            }
        }
    }
    for(auto &itr : mpp){
        ans.push_back(itr.second->val);
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
    vector<int>ans;
    topView(root,ans);
    print(ans);
    return 0;
}