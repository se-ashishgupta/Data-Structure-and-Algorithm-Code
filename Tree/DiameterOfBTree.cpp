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
        return max(height(root->left), height(root->right)) + 1;
}
int diameterNaive(Node *root) // TC:theta(n*n)
{
    if (root == NULL)
        return 0;
    int d1 = 1 + height(root->left) + height(root->right);
    int d2 = diameterNaive(root->left);
    int d3 = diameterNaive(root->right);
    return max(d1, max(d2, d3));
}
int res = 0;
int heightwithDiamter(Node *root) // TC:theta(n*n)
{
    if (root == NULL)
        return 0;
    int lh = heightwithDiamter(root->left);
    int rh = heightwithDiamter(root->right);
    res = max(res, (1 + lh + rh));
    return 1 + max(lh, rh);
}
int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->right->left = new Node(3);
    root->right->right = new Node(9);
    cout << heightwithDiamter(root) << endl;
    cout << res << endl;
}