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

Node *BTToDLL(Node *root)
{
    static Node *prev = NULL;
    if (root == NULL)
        return root;
    Node *head = BTToDLL(root->left);
    if (prev == NULL)
        head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BTToDLL(root->right);
    return head;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    Node *res = BTToDLL(root);
    cout << res->key;

    return 0;
}