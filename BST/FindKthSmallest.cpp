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
int count = 0;
void kthSmallest(Node *root, int k)
{

    if (root != NULL)
    {
        kthSmallest(root->left, k);
        count++;
        if (count == k)
        {
            cout << root->key;
            return;
        }
        kthSmallest(root->right, k);
    }
}
void kthSmallest()
{
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
    kthSmallest(root, 2);

    return 0;
}