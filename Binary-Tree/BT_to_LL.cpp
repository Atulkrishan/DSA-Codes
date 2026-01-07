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
void BT_to_LL(TreeNode *root)
{
    TreeNode* temp = root;
    while(temp){
        if(temp->left){
            TreeNode* ptr = temp->left;
            while(ptr->right){
                ptr = ptr->right;
            }
            ptr->right = temp->right;
            temp->right = temp->left;
            temp->left = nullptr;
        }
        temp = temp->right;
    }
    return ;
}
void Recursive(TreeNode *root,TreeNode** dubprev){
    if(!root)return;
    Recursive(root->right,dubprev);
    Recursive(root->left,dubprev);
    root->right = *dubprev;
    root->left = nullptr;
    *dubprev = root;
    return;
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
    TreeNode* prev = nullptr;
    Recursive(root,&prev);
    while(root){
        cout<<root->val<<" ";
        root = root->right;
    }
    return 0;
}