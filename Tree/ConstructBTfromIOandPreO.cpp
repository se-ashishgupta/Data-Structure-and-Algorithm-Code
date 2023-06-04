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
int preIndex = 0;
Node *cTree(int in[], int pre[], int is, int ie)
{
    if (is > ie)
        return NULL;
    Node *root = new Node(pre[preIndex++]);

    int inIndex;
    for (int i = is; i <= ie; i++)
    {
        if (in[i] == root->key)
        {
            inIndex = i;
            break;
        }
    }
    root->left = cTree(in, pre, is, inIndex - 1);
    root->right = cTree(in, pre, inIndex + 1, ie);
    return root;
}
int main()
{
    int in[] = {20, 10, 40, 30, 50};
    int pre[] = {10, 20, 30, 40, 50};
    Node *res = cTree(in, pre, 0, 4);
    cout << res->left->key;
    return 0;
}