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
void nodesAtDistanceOfK(TreeNode* root, int& maxANS, int ans,map<TreeNode*, int>& mpp,map<TreeNode*,TreeNode*>& parent) {
        if (!root || mpp[root] == 1){
            return;
        }
        maxANS = max(ans,maxANS);
        mpp[root] = 1;
        nodesAtDistanceOfK(root->left, maxANS, ans + 1 , mpp, parent);
        nodesAtDistanceOfK(root->right, maxANS, ans + 1, mpp, parent);
        nodesAtDistanceOfK(parent[root], maxANS, ans + 1, mpp, parent);
        return;
    }
int minTime(TreeNode* root, int target) {
        int ans = 0;
        map< TreeNode*, int> visited;
        map< TreeNode*,TreeNode*> parent;
        queue<TreeNode*> qu;
        qu.push(root);
        parent[root] = nullptr;
        TreeNode* targetNode = nullptr;
        while (!qu.empty()) {
            int size = qu.size();
            while (size--) {
                TreeNode* top = qu.front();
                qu.pop();
                if(top->val == target){
                    targetNode = top;
                }
                if (top->left) {
                    parent[top->left] = top;
                    qu.push(top->left);
                }
                if (top->right) {
                    parent[top->right] = top;
                    qu.push(top->right);
                }
            }
        }
        nodesAtDistanceOfK(targetNode,ans,0,visited, parent);
        return ans;
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
    cout<<"TOTAL BURNING TIME : " << minTime(root,6);
    print(ans);
    return 0;
}