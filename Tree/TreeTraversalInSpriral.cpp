#include <iostream>
#include <queue>
#include <stack>
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

void spiralTraversal1(Node *root) // Tc:O(n) and item process 4 time
{
    if (root == NULL)
        return;
    queue<Node *> q;
    stack<int> s;
    bool reverse = false;
    q.push(root);
    while (q.empty() == false)
    {
        int count = q.size();
        for (int i = 0; i < count; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (reverse)
                s.push(curr->key);
            else
                cout << curr->key << " ";
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        if (reverse)
        {
            while (s.empty() == false)
            {
                cout << s.top() << " ";
                s.pop();
            }
        }
        reverse = !reverse;
    }
}
void spiralTraversal2(Node *root) // Tc:O(n) and item process 2 time
{
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(root);
    while (s1.empty() == false && !s2.empty() == false)
    {
        while (s1.empty() == false)
        {
            Node *curr = s1.top();
            s1.pop();
            cout << curr->key << " ";
            if (curr->left != NULL)
                s2.push(curr->left);
            if (curr->right != NULL)
                s2.push(curr->right);
        }
        while (s2.empty() == false)
        {
            Node *curr = s2.top();
            s2.pop();
            cout << curr->key << " ";
            if (curr->right != NULL)
                s1.push(curr->right);
            if (curr->left != NULL)
                s1.push(curr->left);
        }
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    spiralTraversal1(root);

    return 0;
}