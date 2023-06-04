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

void vTraversal(Node *root) // TC: O(nlog(hd)+hd)=O(nloghd)   hd is total no of possible horizental distance
{
    map<int, vector<int>> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (q.empty() == false)
    {
        auto p = q.front();
        Node *curr = p.first;
        int hd = p.second;
        mp[hd].push_back(curr->key);
        q.pop();
        if (curr->left != NULL)
            q.push({curr->left, hd - 1});
        if (curr->right != NULL)
            q.push({curr->right, hd + 1});
    }
    for (auto x : mp)
    {
        vector<int> v = x.second;
        for (int y : v)
            cout << y << " ";
        cout << endl;
    }
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(16);
    root->right->right = new Node(40);
    vTraversal(root);
    return 0;
}