#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};
void check(Node *root, int target, vector<int> &path, bool &flag)
{
    if (!root) return;
    if (flag == false)
    check(root->left, target, path, flag);
    if (flag == false)
    check(root->right, target, path, flag);
    if (root->data == target || flag == true)
    {
        path.push_back(root->data);
        flag = true;
        return;
    }
}

bool findPath(Node *root, int target, vector<int> &path)
{           
    bool flag = false;
    check(root, target, path, flag);
    reverse(path.begin(),path.end());
    if (path.empty())
        return false;
    else
        return true;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(8);
    root->left->left->right = nullptr;
    root->left->right = new Node(5);
    root->right->left = nullptr;
    root->right->right = new Node(6);
    root->right->right->left = new Node(9);
    root->right->right->left->left = new Node(11);
    root->right->right->right = new Node(12);
    root->right->right->right->left = new Node(10);

    int target;
    cin>>target;
    vector<int> path;
    if (findPath(root, target, path))
    {
        cout << "Path: ";
        for (int val : path)
            cout << val << " ";
    }
    else
    {
        cout << "No path found.";
    }

    return 0;
}