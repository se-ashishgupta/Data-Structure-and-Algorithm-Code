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

Node *floor(Node *root, int k) // TC: O(h)AS: O(1)
{
    Node *res = NULL;
    while (root != NULL)
    {
        if (root->key == k)
            return root;
        else if (root->key > k)
            root = root->left;
        else
        {
            res = root;
            root = root->right;
        }
    }
    return res;
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
    Node *res = floor(root, 19);
    cout << res->key;

    return 0;
}