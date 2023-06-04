#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

void traverse(Node *head)
{

    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

void nthNodeFromEnd(Node *head, int k)
{
    Node *first = head, *second = head;
    for (int i = 1; i <= k; i++)
    {
        if (first == NULL)
            return;
        first = first->next;
    }
    while (first != NULL)
    {
        second = second->next;
        first = first->next;
    }
    cout << second->data;
}
void nthNodeFromEndNaive(Node *head, int k)
{

    int count = 0;
    Node *curr;
    for (curr = head; curr != NULL; curr = curr->next)
        count++;
    if (count < k)
        return;

    curr = head;
    for (int i = 0; i < count - k; i++)
    {
        curr = curr->next;
    }
    cout << curr->data;
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);
    nthNodeFromEnd(head, 2);

    return 0;
}