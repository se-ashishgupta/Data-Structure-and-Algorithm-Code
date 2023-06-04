#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};
Node *pre = NULL, *first = NULL, *second = NULL;
void fixBST(Node *root) // TC:O(n)  AS:O(h)
{
    if (root == NULL)
        return;
    fixBST(root->left);
    if (pre != NULL && root->key < pre->key)
    {
        if (first == NULL)
            first = pre;
        second = root;
    }
    pre = root;
    fixBST(root->right);
}

int main()
{
    Node *root = new Node(20);
    root->left = new Node(60);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->right = new Node(80);
    root->right->left = new Node(8);
    root->right->right = new Node(100);
    fixBST(root);
    swap(first->key, second->key);

    return 0;
}