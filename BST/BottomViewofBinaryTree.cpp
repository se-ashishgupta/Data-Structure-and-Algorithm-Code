#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <utility>
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

void bottomView(Node *root) // TC: O(nlog(hd)+hd)=O(nloghd)   hd is total no of possible horizental distance
{
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (q.empty() == false)
    {
        auto p = q.front();
        Node *curr = p.first;
        int hd = p.second;

        mp[hd] = curr->key;

        q.pop();
        if (curr->left != NULL)
            q.push({curr->left, hd - 1});
        if (curr->right != NULL)
            q.push({curr->right, hd + 1});
    }
    for (auto x : mp)
    {

        cout << x.second << " ";
    }
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);
    root->left->left = new Node(30);
    root->left->right = new Node(40);
    bottomView(root);
    return 0;
}