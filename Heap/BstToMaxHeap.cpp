#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    
    Node(int x)
    {
        this->left = nullptr;
        this->right = nullptr;
        this->data = x;
    }
};
Node* buildSampleBST()
{
    // heap allocation of memory
    Node* root = new Node(50);
    
    root->left = new Node(30);
    root->right = new Node(70);
    
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    
    return root;
}
void inorder(Node* root, vector<int>& arr) {
    if (!root) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

void postorderAssign(Node* root, vector<int>& arr, int& index) {
    if (!root) return;

    postorderAssign(root->left, arr, index);
    postorderAssign(root->right, arr, index);
    cout << index << " ";
    root->data = arr[index++];
}
void levelOrder(Node *root)
{
    queue<Node *> qu;
    qu.push(root);
    while (!qu.empty()){
        int size = qu.size();
        while(size--){
            Node* top = qu.front();
            qu.pop();
            if(top->left){
                qu.push(top->left);
            }
            if(top->right){
                qu.push(top->right);
            }
            cout<<top->data<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    Node *root = buildSampleBST();
    vector<int> arr;
    inorder(root, arr);
    int n = arr.size();
    int index = 0;
    postorderAssign(root, arr, index);
    cout << endl;
    levelOrder(root);
    return 0;
}
