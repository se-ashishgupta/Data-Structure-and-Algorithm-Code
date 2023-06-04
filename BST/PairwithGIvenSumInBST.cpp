#include <iostream>
#include <unordered_set>
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

bool isPair(Node *root, int sum, unordered_set<int> &st) // TC:O(n)  AS:O(n )
{

    if (root == NULL)
        return false;
    if (isPair(root->left, sum, st) == true)
        return true;
    if (st.find(sum - root->key) != st.end())
        return true;
    else
        st.insert(root->key);
    return isPair(root->right, sum, st);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(16);
    root->right->right = new Node(40);
    unordered_set<int> st;
    cout << isPair(root, 25, st);
    return 0;
}