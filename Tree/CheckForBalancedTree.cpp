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
int height(Node *root)
{
    if (root == NULL)
        return 0;
    else
        max(height(root->left), height(root->right)) + 1;
}
bool CheckBalancedNaive(Node *root) // TC:O(n*n)
{
    if (root == NULL)
        return true;
    int lh = height(root->left);
    int rh = height(root->right);
    return (abs(lh - rh) <= 1 && CheckBalancedNaive(root->left) && CheckBalancedNaive(root->right));
}
int CheckBalanced(Node *root) // TC:O(n*n)
{
    if (root == NULL)
        return 0;
    int lh = CheckBalanced(root->left);
    if (lh == -1)
        return -1;
    int rh = CheckBalanced(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    else
        return max(lh, rh) + 1;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    if (CheckBalanced(root) == -1)
        cout << "False";
    else
        cout << "True";

    return 0;
}