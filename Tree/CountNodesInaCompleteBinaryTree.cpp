#include <iostream>
#include <vector>
#include <math.h>
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

int count(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + count(root->left) + count(root->right);
}
// TC:   Best=theta(h)
// In other cases= O(logn*logn)

int countNodes(Node *root)
{
    int lh = 0, rh = 0;
    Node *curr = root;
    while (curr != NULL)
    {
        lh++;
        curr = curr->left;
    }
    curr = root;
    while (curr != NULL)
    {
        rh++;
        curr = curr->right;
    }
    if (lh == rh)
        return pow(2, lh) - 1;
    else
        return 1 + countNodes(root->left) + countNodes(root->right);
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->left->left = new Node(24);
    root->left->right = new Node(28);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    cout << countNodes(root);
    return 0;
}
