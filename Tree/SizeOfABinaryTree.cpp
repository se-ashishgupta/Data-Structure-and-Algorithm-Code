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

int Size(Node *root) // TC: O(n) AS: O(h+1)=O(h) h is height of tree
{
    if (root == NULL)
        return 0;
    else
        return 1 + Size(root->left) + Size(root->right);
}
int SizeItrative(Node *root) // TC: O(n) AS: O(h) w is width of tree
{
    if (root == NULL)
        return 0;
    int res = 0;
    queue<Node *> q;
    q.push(root);
    while (q.empty() == false)
    {
        Node *curr = q.front();
        q.pop();
        res++;
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
    return res;
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    cout << SizeItrative(root);

    return 0;
}