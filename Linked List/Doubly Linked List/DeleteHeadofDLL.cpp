#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

Node *insertAtEnd(Node *head, int k)
{
    Node *temp = new Node(k);
    if (head == NULL)
    {
        return temp;
    }

    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;

    return head;
}

void traverse(Node *head)
{
    if (head == NULL)
        return;

    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

Node *deleted(Node *head)
{
    if (head == NULL)
        return head;

    if (head->next == NULL)
    {
        delete (head);
        return NULL;
    }
    else
    {
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
        return head;
    }
}
int main()
{
    Node *head = NULL;
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    head = deleted(head);
    traverse(head);
    return 0;
}
