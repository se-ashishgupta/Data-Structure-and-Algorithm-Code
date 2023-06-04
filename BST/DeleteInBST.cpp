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
Node *getSuccessor(Node *curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
}
Node *Delete(Node *root, int k) // TC: O(h) AS: O(h)
{

    if (root == NULL)
        return root;
    if (root->key > k)
        root->left = Delete(root->left, k);
    else if (root->key < k)
        root->right = Delete(root->right, k);
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *succ = getSuccessor(root);
            root->key = succ->key;
            root->right = Delete(root->right, succ->key);
        }
        return root;
    }
}
Node *DeleteIterative(Node *root, int k) // TC: O(h)AS: O(1)
{
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
    Node *res = DeleteIterative(root, 2);
    cout << root->left->left->left->key;

    return 0;
}