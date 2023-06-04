#include <iostream>
#include <map>
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
void vSumR(Node *root, int hd, map<int, int> &mp)
{
    if (root == NULL)
        return;
    vSumR(root->left, hd - 1, mp);
    mp[hd] += root->key;
    vSumR(root->right, hd + 1, mp);
}
void vSum(Node *root) // TC: O(nlog(hd)+hd)=O(nloghd)   hd is total no of possible horizental distance
{
    map<int, int> mp;
    vSumR(root, 0, mp);
    for (auto sum : mp)
    {
        cout << sum.second << " ";
    }
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(16);
    root->right->right = new Node(40);
    vSum(root);
    return 0;
}