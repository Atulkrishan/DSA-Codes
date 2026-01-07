#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        this->left = nullptr;
        this->right = nullptr;
        this->val = x;
    }
};

TreeNode* buildTree(vector<int>& postOrder, vector<int>& InOrder,
                    int postStart, int postEnd,
                    int inStart, int inEnd,
                    unordered_map<int, int>& mpp) {
    if (postStart > postEnd || inStart > inEnd)
        return nullptr;

    TreeNode* root = new TreeNode(postOrder[postEnd]);
    int inRootIdx = mpp[root->val];
    int numLeft = inEnd - inRootIdx;

    root->left = buildTree(postOrder, InOrder,
                           postStart, postEnd - numLeft - 1,
                           inStart, inRootIdx - 1, mpp);

    root->right = buildTree(postOrder, InOrder,
                            postEnd - numLeft, postEnd - 1,
                            inRootIdx + 1, inEnd, mpp);

    return root;
}
int getHeight(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

string spaces(int n) {
    return string(max(0, n), ' ');
}
void print(TreeNode* root) {

    if (!root) return;

    int h = getHeight(root);

    queue<TreeNode*> q;
    q.push(root);

    int level = 1; // current level
    while (level <= h) {
        int levelSize = q.size();

        // spacing based on remaining height
        int firstGap = (1 << (h - level)) - 1;
        int betweenGap = (1 << (h - level + 1)) - 1;

        // print initial spaces
        cout << spaces(firstGap);

        // print all nodes in this level
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                cout << node->val;
                q.push(node->left);
                q.push(node->right);
            } else {
                cout << " ";
                q.push(nullptr);
                q.push(nullptr);
            }

            // spaces between nodes
            cout << spaces(betweenGap);
        }

        // print branches for this level (skip last)
        if (level != h) {
            cout << spaces((firstGap - 1));
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front(); // just to know if children exist
                if (node) {
                    cout << (node->left ? " " : " ");
                    cout << spaces((betweenGap - 1));
                    cout << (node->right ? " " : " ");
                } else {
                    cout << " ";
                    cout << spaces((betweenGap - 1));
                    cout << " ";
                }
                cout << spaces(2);
            }
            cout << "\n";
        }

        level++;
    }
}

int main() {
    vector<int> postOrder = {4,5,2,6,7,3,1};
    vector<int> Inorder  = {4,2,5,1,6,3,7};

    unordered_map<int, int> mpp;
    for (int i = 0; i < Inorder.size(); i++) {
        mpp[Inorder[i]] = i;
    }

    TreeNode* root = buildTree(postOrder, Inorder,
                               0, postOrder.size() - 1,
                               0, Inorder.size() - 1,  
                               mpp);

    print(root);
    return 0;
}