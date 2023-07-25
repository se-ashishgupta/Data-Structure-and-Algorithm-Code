#include <iostream>
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

// print (k+1)th level of binary tree

void printKDist(Node *root, int k) // TC: O(n) AS: O(h) h is height of tree
{
    if (root == NULL)
        return;
    if (k == 0)
    {
        cout << root->key << " ";
    }
    else
    {
        printKDist(root->left, k - 1);
        printKDist(root->right, k - 1);
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    printKDist(root, 0);

    return 0;
}