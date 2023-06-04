#include <iostream>
#include <queue>
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

bool search(Node *root, int k) // TC: O(h) AS: O(h)
{
    if (root == NULL)
        return false;
    if (root->key == k)
    {
        return true;
    }
    else if (root->key > k)
        return search(root->left, k);
    else
        return search(root->right, k);
}
bool searchIterative(Node *root, int k) // TC: O(h)AS: O(1)
{
    while (root != NULL)
    {
        if (root->key == k)
            return true;
        else if (root->key > k)
            root = root->left;
        else
            root = root->right;
    }
    return false;
}

int main()
{
    Node *root = new Node(15);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->left->left = new Node(16);
    root->right->right = new Node(80);
    cout << searchIterative(root, 18);

    return 0;
}