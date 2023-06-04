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
bool isBST(Node *root, int min, int max) // TC:O(n)  AS:O(h)
{
    if (root == NULL)
        return true;
    return (root->key > min && root->key < max && isBST(root->left, min, root->key) && isBST(root->right, root->key, max));
}
int p = INT16_MIN;
bool isBST1(Node *root) // TC:O(n)  AS:O(h)
{
    if (root == NULL)
        return true;
    if (isBST1(root->left) == false)
        return false;
    if (root->key <= p)
        return false;
    p = root->key;
    return isBST1(root->right);
}

int main()
{
    Node *root = new Node(15);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->left->left = new Node(16);
    root->right->left->right = new Node(17);
    root->right->right = new Node(80);
    cout << isBST(root, INT16_MIN, INT16_MAX);
    cout << isBST1(root);

    return 0;
}