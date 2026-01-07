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

bool findPath(Node *root, int target, vector<int> &path)
{
    if(!root)return false;
    path.push_back(root->data);
    if(root->data == target){
        return true;
    }
    if(findPath(root->left,target,path) || findPath(root->right,target,path)){
        return true;
    }
    else{
        path.pop_back();
        return false;
    }
}

int main()  
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    int target;
    cin >> target;
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