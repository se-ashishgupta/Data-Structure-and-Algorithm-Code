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

// Height of binary tree is maximum no of nodes from root to a leaft path
// or No of edges in Binary Tree
int height(Node *root) // TC: O(n) AS: Theta(h+1)=Theta(h) h is height of tree
{
    if (root == NULL)
        return 0;
    else
        return max(height(root->left), height(root->right)) + 1;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    cout << height(root);

    return 0;
}