#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
int search1(Node *head, int k) // Iterative    TC:(n)    AS:O(1)
{
    int pos = 1;
    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == k)
            return pos;
        else
        {
            pos++;
            curr = curr->next;
        }
    }
    return -1;
}
int search(Node *head, int k) // Recursive    TC:(n)   AS:O(n)
{
    if (head == NULL)
        return -1;
    if (head->data == k)
        return 1;
    else
    {
        int res = search(head->next, k);
        if (res == -1)
            return -1;
        else
            return res + 1;
    }
}
int main()
{

    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    cout << search(head, 40);
}