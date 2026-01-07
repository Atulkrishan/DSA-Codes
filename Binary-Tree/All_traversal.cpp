#include<bits/stdc++.h>
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),right(right) {} };
void allorder(TreeNode* root){
    stack<pair<TreeNode*,int>>st;
    st.push({root,1});
    vector<int>pre;
    vector<int>ino;
    vector<int>pos;
    while(!st.empty()){
        auto it = st.top();
        st.pop();
        if (it.second==1){
            st.push({it.first,it.second+1});
            pre.push_back(it.first->val);
            if (it.first->left!=nullptr){
                st.push({it.first->left,1});
            }
        }
        else if(it.second==2){
            st.push({it.first,it.second+1});
            ino.push_back(it.first->val);
            if (it.first->right!=nullptr){
                st.push({it.first->right,1});
            }
        }
        else{
            pos.push_back(it.first->val);
        }
    }
}
int main(){
    return 0;
}