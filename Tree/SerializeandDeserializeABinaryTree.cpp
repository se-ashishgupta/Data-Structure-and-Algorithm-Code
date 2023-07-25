#include <iostream>
#include <vector>
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
const int EMPTY = -1;

void serialize(Node *root, vector<int> &arr)
{
    if (root == NULL)
    {
        arr.push_back(EMPTY);
        return;
    }
    arr.push_back(root->key);
    serialize(root->left, arr);
    serialize(root->right, arr);
}
int index = 0;
Node *deserialize(vector<int> &arr)
{
    if (index == arr.size())
        return NULL;
    int val = arr[index];
    index++;
    if (val == EMPTY)
        return NULL;
    Node *root = new Node(val);
    root->left = deserialize(arr);
    root->right = deserialize(arr);
    return root;
}

// Both having TC Theta(n) and AS Theta(n)
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    vector<int> arr;
    serialize(root, arr);
    for (int x : arr)
        cout << x << " ";
    cout << endl;
    Node *curr = deserialize(arr);
    cout << curr->left->key;

    return 0;
}