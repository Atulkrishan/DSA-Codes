#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void morrisTraversal(TreeNode* root){
    TreeNode* ptr = root;
    while(ptr){
        TreeNode* temp = ptr->left;
        if(!temp){
            cout<<(ptr->val)<<" ";
            ptr=ptr->right;
        }
        else{
            while(temp->right && temp->right!= ptr){
                temp = temp ->right;
            }
            if(temp->right!= ptr){
                temp->right = ptr;
                ptr=ptr->left;
            }
            else{
                temp->right = nullptr;
                cout<<(ptr->val)<<" ";
                ptr = ptr->right;
            }
        }
    }
}

TreeNode* buildSampleTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);
    return root;
}

int main() {
    TreeNode* root = buildSampleTree();
    morrisTraversal(root);
    return 0;
}