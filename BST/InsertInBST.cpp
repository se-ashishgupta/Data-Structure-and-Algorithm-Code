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

Node *Insert(Node *root, int k) // TC: O(h) AS: O(h)
{

    if (root == NULL)
        return new Node(k);
    else if (root->key > k)
        root->left = Insert(root->left, k);
    else if (root->key < k)
        root->right = Insert(root->right, k);
    return root;
}
Node *InsertIterative(Node *root, int k) // TC: O(h)AS: O(1)
{
    Node *temp = new Node(k);
    Node *parent = NULL, *curr = root;
    while (curr != NULL)
    {
        parent = curr;
        if (curr->key > k)
        {
            curr = curr->left;
        }
        else if (curr->key < k)
        {
            curr = root->right;
        }
        else
            return root;
    }
    if (parent == NULL)
        return temp;
    if (parent->key < k)
        parent->right = temp;
    else
        parent->left = temp;
    return root;
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
    Node *res = InsertIterative(root, 2);
    cout << root->left->left->left->key;

    return 0;
}