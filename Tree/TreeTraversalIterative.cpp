#include <iostream>
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
void inorderTraversal(Node *root) // TC: Theta(n) AS: O(h) h is height of tree
{
    if (root == NULL)
        return;
    stack<Node *> st;
    Node *curr = root;
    while (curr != NULL || st.empty() == false)
    {
        while (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->key << " ";
        curr = curr->right;
    }
}
void preorderTraversal(Node *root) // TC: Theta(n) AS: O(h) h is height of tree
{
    if (root == NULL)
        return;
    stack<Node *> st;
    Node *curr = root;
    // while (curr != NULL || st.empty() == false)
    // {
    //     while (curr != NULL)
    //     {
    //         cout << curr->key << " ";
    //         st.push(curr);
    //         curr = curr->left;
    //     }
    //     curr = st.top();
    //     st.pop();
    //     curr = curr->right;
    // }
    while (curr != NULL || st.empty() == false)
    {
        while (curr != NULL)
        {
            cout << curr->key << " ";
            if (curr->right != NULL)
                st.push(curr->right);
            curr = curr->left;
        }
        if (st.empty() == false)
        {
            curr = st.top();
            st.pop();
        }
    }
}
void preorderTraversal1(Node *root) // TC: O(n) AS: O(n)
{
    if (root == NULL)
        return;
    stack<Node *> st;
    st.push(root);
    while (st.empty() == false)
    {
        Node *curr = st.top();
        cout << curr->key << " ";
        st.pop();
        if (curr->right != NULL)
            st.push(curr->right);
        if (curr->left != NULL)
            st.push(curr->left);
    }
}
void postorderTraversal(Node *root)
{
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    inorderTraversal(root);
    cout << endl;
    preorderTraversal(root);
    cout << endl;
    postorderTraversal(root);
    cout << endl;
    return 0;
}