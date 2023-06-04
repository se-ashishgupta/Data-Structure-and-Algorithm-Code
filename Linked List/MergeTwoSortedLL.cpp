#include <iostream>
#include <unordered_map>
#include <algorithm>
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

Node *MergeTwoSortedLL(Node *a, Node *b) // TC:O(m+n)   AS:O(1)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    Node *head = NULL, *tail = NULL;

    if (a->data <= b->data)
    {
        head = tail = a;
        a = a->next;
    }
    else
    {
        head = tail = b;
        b = b->next;
    }

    while (a != NULL && b != NULL)
    {
        if (a->data <= b->data)
        {
            tail->next = a;
            tail = a;
            a = a->next;
        }
        else
        {
            tail->next = b;
            tail = b;
            b = b->next;
        }
    }

    if (a == NULL)
        tail->next = b;
    else
        tail->next = a;

    return head;
}
void traverse(Node *head)
{

    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    Node *head1 = new Node(5);
    head1->next = new Node(35);
    Node *head2 = MergeTwoSortedLL(head, head1);
    traverse(head2);
    return 0;
}