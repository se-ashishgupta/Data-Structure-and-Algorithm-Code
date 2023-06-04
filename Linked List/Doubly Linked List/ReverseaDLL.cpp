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
    while (curr->next == NULL)
    {
        curr = curr->next;
    }
    curr->next = temp;
    temp->prev = curr;

    return head;
}

Node *reverseDLL(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *prev = NULL;
    Node *curr = head;
    while (curr != NULL)
    {
        prev = curr->prev;
        curr->prev = curr->next;
        curr->next = prev;
        curr = curr->prev;
    }
    return prev->prev;
}

int main()
{
    Node *head = NULL;
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    return 0;
}
